#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int sums[k];
        memset(sums, 0, sizeof(int)*k);
        sums[0] = 1;
        int currentSum = 0;
        for(int i = 0; i < nums.size(); i++){
            currentSum = (currentSum + nums[i]%k + k) % k;
            ans += sums[currentSum];
            sums[currentSum]++;
        }        
        return ans;
    }
};

int main(void){

    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(-3);
    nums.push_back(1);

    Solution s;
    cout << s.subarraysDivByK(nums, 5) << endl;
    return 0;
}