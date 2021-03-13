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
};

int main(void)
{
    Solution s;
    cout << s.convertToTitle(702) << endl;

    return 0;
}
