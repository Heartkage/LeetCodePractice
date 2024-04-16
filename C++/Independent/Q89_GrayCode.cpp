#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> answer(1, 0);
        set<int> sets;
        sets.insert(0);

        for(int i = 0; i < pow(2, n); i++)
        {
            for(int j = 0; j < n; j++)
            {
                int temp = pow(2, j);
                int nextValue = answer[answer.size()-1] ^ temp;
                if(sets.insert(nextValue).second)
                {
                    cout << "Push Back Num: " << nextValue << endl;
                    answer.push_back(nextValue);
                    break;
                }
            }
        }

        return answer;
    }
};


int main(void)
{
    Solution s;
    vector<int> answer = s.grayCode(2);
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
