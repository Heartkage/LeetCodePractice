#include "LeetCode.h"

using namespace std;
using namespace LeetCode;

int Solution60::findAvailableIndex(vector<bool> &table, int index)
{
    if(index > 0)
    {
        int counter = 0;
        for(int i = 0; i < table.size(); i++)
        {
            if(!table[i])
            {
                counter++;
                if(index == counter)
                {
                    table[i] = true;
                    return i + 1;
                }
            }
        }
    }
    else
    {
        for(int i = table.size()-1; i >= 0; i--)
        {
            if(!table[i])
            {
                table[i] = true;
                return i + 1;
            }
        }
    }
    return 0;
}

string Solution60::getPermutation(int n, int k)
{
    vector<int> table = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    vector<bool> usedTable;
    for(int i = 0; i < n; i++)
        usedTable.push_back(false);

    string answer = "";
    int currentValue = k;
    for(int i = n-1; i >= 0; i--)
    {
        char nextChar;

        int remain = currentValue % table[i];
        int result = currentValue / table[i];
        
        if(remain == 0)
            nextChar = findAvailableIndex(usedTable, result) + 48;
        else
            nextChar = findAvailableIndex(usedTable, result + 1) + 48;

        //cout << nextChar << endl;
        answer.push_back(nextChar);
        currentValue = remain;
    }

    return answer;
}

void Solution60::test()
{
    cout << getPermutation(4, 3) << endl;
}
