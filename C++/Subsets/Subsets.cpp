#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        answer.push_back(vector<int>());

        for(int i = 0; i < nums.size(); i++)
        {
            int currentSize = answer.size();
            for(int j = 0; j < currentSize; j++)
            {
                vector<int> list(answer[j]);
                list.push_back(nums[i]);
                answer.push_back(list);
            }
        }
        return answer;
    }
};

int main(void)
{
    Solution s;
    vector<int> list{1, 2, 3};
    vector<vector<int>> answer = s.subsets(list);

    for(int i = 0; i < answer.size(); i++)
    {
        cout << "[";
        for(int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
        }
        cout << "]" << endl;
    }

    return 0;
}