#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = -1000000;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            int currentValue = 0;
            int skipIndex = 0;
            bool seenNegative = false;
            for(int j = i; j < (n+i); j++){
                int index = j % n;
                if(seenNegative == false){
                    if(nums[index] > -1)
                        skipIndex = j - i;
                    else{
                        seenNegative = true;
                    }
                }
                currentValue += nums[index];
                ans = max(ans, currentValue);
                if(currentValue < 0){
                    break;
                }
            }
            i += skipIndex;
        }
        return ans;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(-3);
    nums.push_back(-2);
    nums.push_back(-3);

    Solution s;
    cout << s.maxSubarraySumCircular(nums) << endl;
    return 0;
}