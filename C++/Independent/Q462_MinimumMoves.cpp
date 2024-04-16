#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];
        int answer = 0;
        for(int i = 0; i < nums.size(); i++)
            answer += abs(nums[i] - median);
        return answer;
    }
};


int main(void)
{
    vector<int> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(0);
    input.push_back(8);
    input.push_back(6);

    Solution s;
    cout << s.minMoves2(input) << endl;

    return 0;
}