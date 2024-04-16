#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string answer = "";
        while(columnNumber--)
        {
            int result = columnNumber % 26;
            answer.insert(answer.begin(), 'A' + result);
            columnNumber /= 26;
        }   

        return answer;
    }

    int titleToNumber(string columnTitle) {
        int answer = 0;
        for(int i = columnTitle.size()-1; i >= 0; i--)
            answer += (columnTitle[i] - 64) * pow(26, columnTitle.size() - 1 - i);
        return answer;
    }
};

int main(void)
{
    Solution s;
    cout << s.convertToTitle(702) << endl;

    return 0;
}
