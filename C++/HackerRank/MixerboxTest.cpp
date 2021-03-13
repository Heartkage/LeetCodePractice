#include<iostream>
#include<stack>

using namespace std;


int main(void)
{
    string input = "";

    while(cin >> input)
    {
        stack<char> signStack;
        stack<int> numberStack;

        bool valid = true;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '0')
                numberStack.push(0);
            else if(input[i] == '(')
                signStack.push('(');
            else if(input[i] == '+')
                signStack.push('+');
            else if(input[i] == ')')
            {
                if(i > 0 && input[i - 1] == '(')
                {
                    numberStack.push(0);
                    signStack.pop();
                }    
                else
                {
                    while(!signStack.empty() && signStack.top() != '(')
                    {
                        if(numberStack.size() >= 2)
                        {
                            signStack.pop();
                            numberStack.pop();
                        }
                        else
                        {
                            valid = false;
                            break;
                        }
                    }

                    if(!valid)
                        break;
                    else
                        signStack.pop();
                }
            }
        }

        while(!signStack.empty() && !numberStack.empty())
        {
            if(numberStack.size() >= 2)
            {
                signStack.pop();
                numberStack.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }

        if(valid && signStack.empty() && numberStack.size() == 1)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }

    return 0;
}