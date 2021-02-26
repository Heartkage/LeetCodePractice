#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int RecursivelySearchMinimum(vector<int> &nums, int leftIndex, int rightIndex)
    {
        //cout << "CurrentIndex: " << leftIndex << ", right: " << rightIndex << endl;
        if(leftIndex == rightIndex)
            return nums[leftIndex];

        int midIndex = (leftIndex + rightIndex) / 2;

        if(nums[midIndex] >= nums[leftIndex] && nums[midIndex] >= nums[rightIndex])
        {
            //cout << "Choose Range: " << nums[midIndex + 1] << ", " << nums[rightIndex] << endl;
            return RecursivelySearchMinimum(nums, midIndex + 1, rightIndex);
        }
        else
        {
            //cout << "Choose Range: " << nums[leftIndex] << ", " << nums[midIndex] << endl;
            return RecursivelySearchMinimum(nums, leftIndex, midIndex);
        }
    }
public:
    int findMin(vector<int>& nums) {
        return RecursivelySearchMinimum(nums, 0, nums.size()-1);
    }
};

int main(void)
{
    Solution s;
    vector<int> list{0,1,2,3,4,5,6};
    cout << "Answer: " << s.findMin(list) << endl;
    return 0;
}