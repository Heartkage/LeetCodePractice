#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 1;

        int maxL = 1;
        int startIndex = 0; 
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                if (i > 1 && nums[i-1] < nums[i-2]) {
                    maxL = max(maxL, i - startIndex);
                    startIndex = i - 1;
                }
            } else if(nums[i] < nums[i-1]) {
                if (i > 1 && nums[i-1] > nums[i-2]) {
                    maxL = max(maxL, i - startIndex);
                    startIndex = i - 1;
                }
            } else {
                maxL = max(maxL, i - startIndex);
                startIndex = i;
            }
        }

        return max(maxL, n - startIndex);
    }
};

int main(void) {
    vector<int> input = {1, 4, 3, 2};

    Solution s;
    cout << s.longestMonotonicSubarray(input) << endl;

    return 0;
}