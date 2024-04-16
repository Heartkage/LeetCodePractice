#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min = 2147483647;
        int minDeviation = min;

        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1)
                nums[i] *= 2;
            if(nums[i] < min)
                min = nums[i];
            pq.push(nums[i]);
        }

        while(true){
            int max = pq.top();
            pq.pop();
            if((max-min) < minDeviation)
                minDeviation = max-min;
            if(max & 1)
                break;
            else{
                int newMin = max/2;
                if(min > newMin)
                    min = newMin;
                pq.push(newMin);
            }
        }
        return minDeviation;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    Solution s;
    cout << s.minimumDeviation(nums) << endl;
    return 0;
}