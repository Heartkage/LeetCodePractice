#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maximum = 0;
        int sum = nums[0];
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                sum += nums[i];
            } else {
                maximum = max(maximum, sum);
                sum = nums[i];
            }
        }

        return max(maximum, sum);
    }
};

int main(void) {
    
    vector<int> input = {1,2,3,4,5,1,10,30};

    Solution s;
    cout << "ans: " << s.maxAscendingSum(input) << endl;

    return 0;
}