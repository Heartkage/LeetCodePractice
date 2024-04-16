#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int RecursivelySearchMinimum(vector<int> &nums, int leftIndex, int rightIndex)
    {
        cout << "CurrentIndex: " << leftIndex << ", right: " << rightIndex << endl;
        if(leftIndex == rightIndex)
            return nums[leftIndex];

        int midIndex = (leftIndex + rightIndex) / 2;

        if(nums[midIndex] == nums[leftIndex] && nums[midIndex] == nums[rightIndex])
        {
            int left = RecursivelySearchMinimum(nums, leftIndex, midIndex);
            int right = RecursivelySearchMinimum(nums, midIndex + 1, rightIndex);
            return min(left, right);
        }
        else if(nums[midIndex] >= nums[leftIndex] && nums[midIndex] > nums[rightIndex])
        {
            cout << "Choose Range: " << nums[midIndex + 1] << ", " << nums[rightIndex] << endl;
            return RecursivelySearchMinimum(nums, midIndex + 1, rightIndex);
        }
        else
        {
            cout << "Choose Range: " << nums[leftIndex] << ", " << nums[midIndex] << endl;
            return RecursivelySearchMinimum(nums, leftIndex, midIndex);
        }
    }

    int RecursivelySearchTarget(vector<int> &nums, int _target, int leftIndex, int rightIndex)
    {
        cout << "CurrentIndex: " << leftIndex << ", right: " << rightIndex << endl;
        if(leftIndex == rightIndex)
        {
            if(nums[leftIndex] == _target)
                return leftIndex;
            else
                return -1;
        }
        
        int midIndex = (leftIndex + rightIndex) / 2;

        if(nums[midIndex] >= nums[leftIndex] && nums[midIndex] > nums[rightIndex])
        {
            if(nums[leftIndex] <= _target && _target <= nums[midIndex])
            {
                cout << "Choose Range: " << nums[leftIndex] << ", " << nums[midIndex] << endl;
                return RecursivelySearchTarget(nums, _target, leftIndex, midIndex);
            }
            else 
            {
                cout << "Choose Range: " << nums[midIndex + 1] << ", " << nums[rightIndex] << endl;
                return RecursivelySearchTarget(nums, _target, midIndex + 1, rightIndex);
            }
        }
        else
        {
            if(nums[midIndex] < _target && _target <= nums[rightIndex])
            {
                cout << "Choose Range: " << nums[midIndex + 1] << ", " << nums[rightIndex] << endl;
                return RecursivelySearchTarget(nums, _target, midIndex + 1, rightIndex);
            }
            else
            {
                cout << "Choose Range: " << nums[leftIndex] << ", " << nums[midIndex] << endl;
                return RecursivelySearchTarget(nums, _target, leftIndex, midIndex);
            }
        }
    }
public:
    int findMin(vector<int>& nums) {
        return RecursivelySearchMinimum(nums, 0, nums.size()-1);
    }
    int search(vector<int>& nums, int target) {
        return RecursivelySearchTarget(nums, target, 0, nums.size()-1);
    }
};

int main(void)
{
    Solution s;
    vector<int> list{4,5,6,7,8,1,2,3};
    for(int i = 0; i < list.size(); i++)
        cout << list[i] << " ";
    cout << endl;
    cout << "Answer: " << s.search(list, 5) << endl;
    return 0;
}