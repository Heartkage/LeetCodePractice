#include<iostream>
#include<vector>

using namespace std;

class Solution34 {
    int beginIndex;
    int lastIndex;
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        beginIndex = -1;
        lastIndex = -1;

        vector<int> answer;
        BinarySearch(nums, 0, nums.size(), target);

        answer.push_back(beginIndex);
        answer.push_back(lastIndex);
        return answer;
    }

    void BinarySearch(vector<int>& nums, int left, int right, int target)
    {
        if(left >= right)
            return;
        else
        {
            int midIndex = (left + right) / 2;
            int midValue = nums[midIndex];

            if(midValue > target)
                BinarySearch(nums, left, midIndex, target);
            else if(midValue < target)
                BinarySearch(nums, midIndex+1, right, target);
            else
            {
                beginIndex = lastIndex = midIndex;
                cout << "Left: " << left << endl;
                cout << "Mid: " << midIndex << endl;
                cout << "Right: " << right << endl;

                L_BinarySearch(nums, left, midIndex, target);
                R_BinarySearch(nums, midIndex+1, right, target);
            }
        }
    }

    void L_BinarySearch(vector<int> &nums, int left, int right, int target)
    {
        if(left >= right)
            return;
        else
        {
            int midIndex = (left + right) / 2;
            int midValue = nums[midIndex];

            if(midValue < target)
                L_BinarySearch(nums, midIndex+1, right, target);
            else
            {
                beginIndex = midIndex;
                //cout << "Update BeginIndex: " << beginIndex << endl;
                L_BinarySearch(nums, left, midIndex, target);
            }
        }
    }

    void R_BinarySearch(vector<int> &nums, int left, int right, int target)
    {
        if(left >= right)
            return;
        else
        {
            int midIndex = (left + right) / 2;
            int midValue = nums[midIndex];

            if(midValue > target)
                R_BinarySearch(nums, left, midIndex, target);
            else
            {
                lastIndex = midIndex;
                //cout << "Update LastIndex: " << lastIndex << endl;
                R_BinarySearch(nums, midIndex+1, right, target);
            }
        }
    }
};

int main(void)
{
    Solution34 solution;
    vector<int> input;
    input.push_back(5);
    input.push_back(7);
    input.push_back(7);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(8);
    input.push_back(10);


    for(int i = 0; i < input.size(); i++)
        cout << i << " ";
    cout << endl;
    for(int i = 0; i < input.size(); i++)
        cout << input[i] << " ";
    cout << endl;

    vector<int> output = solution.searchRange(input, 10);
    cout << "Answer: ";
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }


    return 0;
}