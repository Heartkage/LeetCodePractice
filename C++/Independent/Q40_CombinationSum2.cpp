#include<iostream>
#include<vector>

using namespace std;

class Solution {
    vector<vector<int> > answer;
    vector<int> current;

    void recursiveSearch(vector<int>& candidates, int index, int remainValue)
    {
        if(remainValue == 0)
        {
            answer.push_back(current);
            return;
        }

        int lastValue = -1;
        for(int i = index; i < candidates.size(); i++)
        {
            if(candidates[i] > remainValue)
                return;
            else if(candidates[i] == lastValue)
                continue;
            else
            {
                lastValue = candidates[i];
                
                current.push_back(lastValue);
                remainValue -= lastValue;
                recursiveSearch(candidates, i + 1, remainValue);
                remainValue += lastValue;
                current.pop_back();
            }
        }
    }

public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        answer.clear();
        sort(candidates.begin(), candidates.end());
        recursiveSearch(candidates, 0, target);
        return answer;
    }
};

int main(void)
{
    vector<int> input;
    //input.push_back(10);
    input.push_back(2);
    input.push_back(5);
    input.push_back(2);
    input.push_back(1);
    input.push_back(2);
    //input.push_back(5);

    Solution s;

    vector<vector<int> > output = s.combinationSum2(input, 5);

    cout << "Answer: " << endl;
    for(int i = 0; i < output.size();i++)
    {
        for(int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}