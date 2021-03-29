#include<iostream>
#include<vector>
using namespace std;

class Solution128 {
private:

    int Partition(vector<int>& _nums, int _startIndex, int _endIndex)
    {
        int pivot = _nums[_endIndex];
        int i = _startIndex - 1;
        cout << "Pivot: " << pivot << endl;
        cout << "currentVal: " << _nums[i+1] << endl;
        for(int j = _startIndex; j < _endIndex; j++)
        {
            if(_nums[j] <= pivot)
            {
                i++;
                swap(_nums[i], _nums[j]);
            }
        }

        int middleIndex = i+1;
        cout << "currentVal: " << _nums[middleIndex] << endl;
        swap(_nums[middleIndex], _nums[_endIndex]);

        return middleIndex;
    }

    void QuickSort(vector<int>& _nums, int _startIndex, int _endIndex)
    {
        if(_startIndex < _endIndex)
        {
            int middleIndex = Partition(_nums, _startIndex, _endIndex);
            cout << middleIndex << endl;
            QuickSort(_nums, _startIndex, middleIndex - 1);
            QuickSort(_nums, middleIndex + 1, _endIndex);
        }
    }

public:
    int longestConsecutive(vector<int>& nums) {
        QuickSort(nums, 0, nums.size()-1);

        for(int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;

        int answer = 0;
        if(nums.size() > 0)
        {
            int current = 1;
            for(auto i = 1; i < nums.size(); i++)
            {
                if(nums[i-1] == nums[i])
                    continue;
                else if(nums[i-1]+1 == nums[i])
                    current++;
                else
                {
                    if(current > answer)
                        answer = current;
                    current = 1;
                }
            }

            if(current > answer)
                answer = current;
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {4,2,1,3};
    Solution128 s;

    cout << s.longestConsecutive(nums) << endl;
    
    return 0;
}