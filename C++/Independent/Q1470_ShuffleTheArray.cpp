#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> temp(n);
        for(int i = 0; i < n; i++)
            temp[i] = nums[i+n];
        for(int i = n-1; i > -1; i--){
            nums[i*2+1] = temp[i];
            nums[i*2] = nums[i];
        }
        return nums;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);

    Solution s;
    vector<int> ans = s.shuffle(nums, 3);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;

}