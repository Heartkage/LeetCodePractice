#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+")
            {
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();

                numbers.push(first + second);
            }
            else if(tokens[i] == "-")
            {
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();

                numbers.push(first - second);
            }
            else if(tokens[i] == "*")
            {
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();

                numbers.push(first * second);
            }
            else if(tokens[i] == "/")
            {
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();

                numbers.push(first / second);
            }
            else
            {
                numbers.push(stoi(tokens[i]));
            }
        }
        return numbers.top();
    }
};

int main(void)
{
    Solution s;
    vector<string> words;
    words.push_back("5");
    words.push_back("6");
    words.push_back("+");
    words.push_back("7");
    words.push_back("*");
    cout << s.evalRPN(words) << endl;

    return 0;
}