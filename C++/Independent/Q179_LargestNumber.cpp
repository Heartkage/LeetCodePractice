#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>

using namespace std;

class Solution {
    static bool LargeComparator(int first, int second)
    {
        stringstream ss;
        string firstString, secondString;
        ss << first;
        ss >> firstString;
        ss.clear();
        ss << second;
        ss >> secondString;
        string temp = secondString;
        secondString = secondString.append(firstString);
        firstString = firstString.append(temp);

        /*cout << "First: " << firstString << endl; 
        cout << "Second: " << secondString << endl; 
        cout << "Compare: " << secondString.compare(firstString) << endl;*/
        int compare = firstString.compare(secondString);
        return (compare >= 1) ? true : false;
    }

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), LargeComparator);
        string largeNumber = "";
        
        stringstream ss;
        for(int i = 0; i < nums.size(); i++)
        {
            string temp;
            ss << nums[i];
            ss >> temp;
            ss.clear();
            cout << nums[i] << endl;
            largeNumber = largeNumber.append(temp);
        }
        return largeNumber;
    }
};

int main(void)
{
    vector<int> nums({3,30,34,5,9});

    Solution s;
    cout << "Answer: " << s.largestNumber(nums) << endl;

    return 0;
}