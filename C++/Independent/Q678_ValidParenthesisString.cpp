#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> signStack;
        stack<int> star;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                signStack.push(i);
            else if(s[i] == '*')
                star.push(i);
            else
            {
                if(!signStack.empty())
                    signStack.pop();
                else if(!star.empty() && star.top() < i)
                    star.pop();
                else
                    return false;
            }
        }

        while(!signStack.empty() && !star.empty())
        {
            if(signStack.top() < star.top())
            {
                signStack.pop();
                star.pop();
            }
            else
                break;
        }

        return signStack.empty();
    }
};

int main(void)
{
    Solution s;

    cout << s.checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;

    return 0;
}
