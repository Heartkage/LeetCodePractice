#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> table(101, 0);

        for(int i = 0; i < nums.size(); i++){
            if(table[nums[i]] < 2)
                table[nums[i]]++;
            else
                return false;
        }
        return true;
    }

    // 2 <= n <= 10^3
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long largestArea = 0;
        int n = bottomLeft.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int endX = min(topRight[i][0], topRight[j][0]);
                int endY = min(topRight[i][1], topRight[j][1]);
                int startX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int startY = max(bottomLeft[i][1], bottomLeft[j][1]);

                if(endX > startX && endY > startY){
                    long long minSide = min(endX - startX, endY - startY);
                    largestArea = max(largestArea, minSide * minSide);
                }
            }
        }
        return largestArea;
    }

    // Unsolved
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size();
        int s = changeIndices.size();

        vector<int> order;
        vector<int> steps;
        set<int> exist;
        for(int i = s-1; i>=0; i--){
            if(exist.find(changeIndices[i] - 1) == exist.end()){
                int index = changeIndices[i] - 1;
                order.insert(order.begin(), index);
                steps.insert(steps.begin(), 0);
                exist.insert(index);
                // cout << "i:" << index << endl;
            }
            else{
                steps[0]++;
                // cout << steps[0] << endl;
            }
        }

        if(order.size() != n){
            // cout << order.size() << endl;
            return -1;
        }

        int orderIndex = 0;
        int nextOrderIndex = 0;
        for(int i = 0; i < s; i++){
            int reduceIndex = order[orderIndex];
            if(nums[reduceIndex] > 0 && steps[orderIndex] < nums[reduceIndex]){
                // cout << "i: " << i << ",s:" << steps[orderIndex] << ", " << nums[reduceIndex] << endl;
                return -1;
            }
            else if(nums[reduceIndex] == 0 && (changeIndices[i] == reduceIndex+1)){
                orderIndex++;
                if(orderIndex == n)
                    return i+1;
            }
            else if(nums[reduceIndex] > 0){
                nums[reduceIndex]--;
                steps[orderIndex]--;
            }
            else{
                while(nextOrderIndex < n && nums[nextOrderIndex] == 0)
                    nextOrderIndex++;
                if(nextOrderIndex < n){
                    nums[nextOrderIndex]--;
                    steps[nextOrderIndex]--;
                }
            }
        }
        
        return -1;
    }
};



int main(void){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(0);
    vector<int> s;
    s.push_back(2);
    s.push_back(2);
    s.push_back(2);
    s.push_back(2);
    s.push_back(3);
    s.push_back(2);
    s.push_back(2);
    s.push_back(1);

    Solution sol;
    cout << sol.earliestSecondToMarkIndices(nums, s) << endl;
    return 0;
}