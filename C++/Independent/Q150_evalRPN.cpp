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

    int evalRPN2(vector<string>& tokens){
        int n = tokens.size();
        int nums[n];
        int top = -1;

        for(int i = 0; i < n; i++){
            if(tokens[i].length() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')){
                nums[++top] = stoi(tokens[i]);
            }
            else{
                int v2 = nums[top];
                int v1 = nums[--top];

                switch (tokens[i][0])
                {
                case '+':
                    nums[top] = v1+v2;
                    break;
                case '-':
                    nums[top] = v1-v2;
                    break;
                case '*':
                    nums[top] = v1*v2;
                    break;
                default:
                    nums[top] = v1/v2;
                    break;
                }
            }
        }
        return nums[top];
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
    cout << s.evalRPN2(words) << endl;

    return 0;
}