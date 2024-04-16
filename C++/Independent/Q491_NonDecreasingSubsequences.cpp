#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
    map<vector<int>, int> map;
    void RecursiveSearch(vector<int> &nums, vector<vector<int> > &ans, vector<int> &currentAns, int index){
        for(int i = index + 1; i < nums.size(); i++){
            if(index == -1){
                currentAns.push_back(nums[i]);
                RecursiveSearch(nums, ans, currentAns, i);
                currentAns.pop_back();
            }
            else if(nums[index] <= nums[i]){
                currentAns.push_back(nums[i]);
                map[currentAns]++;
                if(map[currentAns] < 2)
                    ans.push_back(currentAns);
                RecursiveSearch(nums, ans, currentAns, i);
                currentAns.pop_back();
            }
        }
    }
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> currentAns;
        map.clear();
        RecursiveSearch(nums, ans, currentAns, -1);

        return ans;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    Solution s;
    vector<vector<int> > ans = s.findSubsequences(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}