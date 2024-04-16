#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > answer;
        map<int, vector<vector<int> > > dp;
        map<int, vector<vector<int> > >::iterator iter;

        for(int i = 1; i <= target; i++)
        {
            map<int, bool> usedCandidate;
            map<int, bool>::iterator usedIter;

            for(int j = 0; j < candidates.size(); j++)
            {
                int remainValue = i - candidates[j];
                iter = dp.find(remainValue);

                if(remainValue == 0)
                {
                    vector<int> answer;
                    answer.push_back(candidates[j]);
                    vector<vector<int> > result;
                    result.push_back(answer);

                    iter = dp.find(i);
                    if(iter == dp.end())
                        dp.insert(pair<int, vector<vector<int> > >(candidates[j], result));
                    else
                        dp[i].push_back(answer);
                }
                else if(iter != dp.end())
                {
                    vector<vector<int> > result = iter->second;
                    vector<vector<int> > currentResult;

                    if(dp.find(i) == dp.end())
                    {
                        dp.insert(pair<int, vector<vector<int> > >(i, currentResult));
                    }

                    for(int k = 0; k < result.size(); k++)
                    {
                        vector<int> singleResult = result[k];
                        vector<int> newSingleResult(singleResult);
                        int lastIndex = newSingleResult.size()-1;
                        if(newSingleResult[lastIndex] <= candidates[j])
                        {
                            newSingleResult.push_back(candidates[j]);
                            dp[i].push_back(newSingleResult);
                        }

                    }
                }
            }
        
            printMap(dp);
        }
        
        iter = dp.find(target);
        if(iter != dp.end())
        {
            answer = iter->second;
        }

        return answer; 
    }

    void printMap(map<int, vector<vector<int > > >& dp)
    {
        cout << "-----Check dp Values-----" << endl;
        map<int, vector<vector<int> > >::iterator iter = dp.begin();
        while(iter != dp.end())
        {
            cout << "Current: " << iter->first << endl;
            vector<vector<int> > result = iter->second;
            for(int i = 0; i < result.size(); i++)
            {
                for(int j = 0; j < result[i].size(); j++)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }

            iter++;
        }

        cout << "-----End of Checkup-----" << endl;
    }
};

int main(void)
{
    Solution s;
    vector<int> input;
    input.push_back(2);
    input.push_back(3);
    input.push_back(5);
    input.push_back(6);
    input.push_back(7);

    vector<vector<int> > output = s.combinationSum(input, 8);

    cout << "answer: " << endl;
    for(int i = 0; i < output.size(); i++)
    {
        for(int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}