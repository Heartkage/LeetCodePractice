#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid = 0;

        while(left < right){
            mid = (left + right) / 2;
            if(nums[mid] ^ target){
                if(target < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            else
                return mid;
        }
        return left;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    
    Solution s;
    cout << "Target 0 = " << s.searchInsert(nums, 0) << endl;
    cout << "Target 1 = " << s.searchInsert(nums, 1) << endl;
    cout << "Target 2 = " << s.searchInsert(nums, 2) << endl;
    cout << "Target 3 = " << s.searchInsert(nums, 3) << endl;
    cout << "Target 4 = " << s.searchInsert(nums, 4) << endl;
    cout << "Target 5 = " << s.searchInsert(nums, 5) << endl;
    cout << "Target 6 = " << s.searchInsert(nums, 6) << endl;
    cout << "Target 7 = " << s.searchInsert(nums, 7) << endl;

    return 0;
}