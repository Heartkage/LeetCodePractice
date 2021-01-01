#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:

public:
    // Q119
    vector<int> getRow(int rowIndex) {
        vector<int> answer;

        answer.push_back(1);

        while(rowIndex--)
        {
            answer.push_back(1);
            int leftValue = 1;
            int rightValue;
            for(int i = 1; i < answer.size()-1; i++)
            {
                rightValue = answer[i];
                answer[i] = leftValue + answer[i];
                leftValue = rightValue;
            }
        }

        return answer;
    }
};

int main()
{
    Solution solution;

    vector<int> answers = solution.getRow(5);
    for(int i = 0; i < answers.size(); i++)
        cout << answers[i] << " ";
    cout << endl;

    return 0;
}