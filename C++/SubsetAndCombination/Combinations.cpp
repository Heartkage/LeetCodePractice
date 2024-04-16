#include<iostream>
#include<vector>

using namespace std;

class Solution {
    vector<vector<int>> answers;
    int maxDepth;
    void recursionCreate(vector<int> &current, vector<bool> truthTable)
    {
        if(current.size() == maxDepth)
        {
            answers.push_back(current);
        }
        else
        {
            for(int i = 0; i < truthTable.size(); i++)
            {
                if(!truthTable[i])
                {
                    current.push_back(i + 1);
                    truthTable[i] = true;
                    recursionCreate(current, truthTable);
                    current.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        answers.clear();
        maxDepth = k;
        vector<int> combination;
        vector<bool> truthTable(n, false);
        recursionCreate(combination, truthTable);
        
        return answers;
    }
};

int main(void)
{
    Solution s;
    
    vector<vector<int>> answer = s.combine(4, 2);

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

