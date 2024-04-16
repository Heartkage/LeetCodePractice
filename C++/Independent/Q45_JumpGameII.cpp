#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        short ans = 0;
        short n = nums.size() - 1;
        if(n == 0)
            return ans;

        short target = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] + i > nums[i - 1])
                nums[i] = nums[i] + i;
            else
                nums[i] = nums[i-1];

            if(!((target-i) ^ 0)){
                target = nums[i];
                ans++;
            }
        }
        return ans + 1;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);


    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}