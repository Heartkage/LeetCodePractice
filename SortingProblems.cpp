#include<iostream>
#include<vector>
using namespace std;

class Solution128 {
private:
    void QuickSort(vector<int>& _nums, int _startIndex, int _endIndex)
    {
        if(_startIndex >= _endIndex)
            return;

        int pivot = _nums[_startIndex];
        int i = _startIndex, j = _endIndex - 1;
        while(j > i)
        {
            while((i < j) && (_nums[i] < pivot)) i++;
            while((j > i) && (_nums[j] > pivot)) j--;

            if(j > i)
                swap(_nums[i], _nums[j]);
            else
                swap(_nums[i], _nums[_startIndex]);
        }
        QuickSort(_nums, _startIndex, i);
        QuickSort(_nums, i+1, _endIndex);
    }

public:
    int longestConsecutive(vector<int>& nums) {
        QuickSort(nums, 0, nums.size());

        for(auto i : nums)
            cout << nums[i] << " ";
        cout << endl;

        int answer = 0;
        if(nums.size() > 0)
        {
            int current = 1;
            for(auto i = 1; i < nums.size(); i++)
            {
                if(nums[i-1]+1 == nums[i])
                    current++;
                else
                {
                    if(current > answer)
                        answer = current;
                    current = 1;
                }
            }
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution128 s;

    cout << s.longestConsecutive(nums) << endl;
    
    return 0;
}