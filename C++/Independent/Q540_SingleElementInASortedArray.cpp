#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int ans;
    void recursiveSearch(vector<int>& nums, int left, int right){
        int mid = (left+right)/2;
        if(mid == left){
            if(left == 0)
                ans = nums[left];
            else if(nums[left] ^ nums[left-1])
                ans = nums[left];
            else
                ans = nums[right];
        }
        else if((right-mid) & 1){
            if(nums[mid] == nums[mid+1])
                recursiveSearch(nums, left, mid-1);
            else
                recursiveSearch(nums, mid+1, right);
        }
        else{
            if(nums[mid] ^ nums[mid+1])
                recursiveSearch(nums, left, mid);
            else{
                recursiveSearch(nums, mid+1, right);
            }
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        //recursiveSearch(nums, 0, nums.size()-1);
        int left = 0;
        int right = nums.size()-1;
        while(1){
            int mid = (left+right)/2;
        if(mid == left){
            if(left == 0)
                ans = nums[left];
            else if(nums[left] ^ nums[left-1])
                ans = nums[left];
            else
                ans = nums[right];
            break;
        }
        else if((right-mid) & 1){
            if(nums[mid] == nums[mid+1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else{
            if(nums[mid] ^ nums[mid+1])
                right = mid;
            else{
                left = mid + 1;
            }
        }
        }
        return ans;
    }
};

int main(void){
    vector<int> nums;
    nums.push_back(1);

    Solution s;
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}