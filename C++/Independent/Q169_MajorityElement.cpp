#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        int currentHighestNum;

        for(auto &i : nums)
        {
            if(table.count(i) == 0)
                table[i] = 0;
            table[i]++;

            if(currentHighestNum != i)
                if(table[currentHighestNum] < table[i])
                    currentHighestNum = i;
        }
        return currentHighestNum;
    }
};

int main(void)
{
    Solution s;

    vector<int> nums{2,2,1,1,1,2,2};

    cout << s.majorityElement(nums) << endl;

    return 0;
}