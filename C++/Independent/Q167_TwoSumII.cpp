#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while(i < j)
        {
            while((numbers[j] + numbers[i]) > target)
                --j;
            if(numbers[j] + numbers[i] == target)
                break;
            ++i;
        }
        vector<int> answer;
        answer.push_back(i+1);
        answer.push_back(j+1);
        return answer;
    }
};

int main(void)
{
    vector<int> input;
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    Solution s;
    vector<int> output = s.twoSum(input, 6);
    cout << output[0] << ", " << output[1] << endl;
    return 0;
}