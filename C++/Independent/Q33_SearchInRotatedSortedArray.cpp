#include<iostream>
using namespace std;

class Solution {
    int recursiveSearch(vector<int> &nums, int target, int left, int right){
        int ans = -1;
        if(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                ans = mid;
            else{
                if(target < nums[mid] && (nums[left] <= target || nums[left] > nums[mid]))
                    ans = recursiveSearch(nums, target, left, mid);
                else if(target < nums[mid])
                    ans = recursiveSearch(nums, target, mid + 1, right);
                else if(nums[mid] < target && (target <= nums[right - 1] || nums[right - 1] < nums[mid]))
                    ans = recursiveSearch(nums, target, mid + 1, right);
                else
                    ans = recursiveSearch(nums, target, left, mid);
            }
        }
        return ans;
    }
public:
    int search(vector<int>& nums, int target) {
        return recursiveSearch(nums, target, 0, nums.size());
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);


    Solution s;
    int start = 0;
    int end = 10;
    for(int i = start; i < end; i++)
        cout << "ans (" << i << "): " << s.search(nums, i) << endl;
    return 0;
}