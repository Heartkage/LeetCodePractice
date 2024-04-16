#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int front = 0;
        int back = 0;
        for(int i = 0; i < n; i++)
            front += nums[i];
        for(int i = 0; i < n; i++){
            front -= nums[i];
            ans[i] = front + nums[i] * (2 * i - n + 1) - back;
            back += nums[i];
        }
        return ans;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(10);

    Solution s;
    auto ans = s.getSumAbsoluteDifferences(nums);
    for(auto& i : ans)
        cout << i << endl;
    return 0;
}