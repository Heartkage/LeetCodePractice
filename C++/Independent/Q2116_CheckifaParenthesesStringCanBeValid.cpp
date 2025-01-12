#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n & 1) {
            return false;
        }

        stack<int> open;
        stack<int> available;

        for(int i=0; i<n; i++) {
            if(locked[i] == '0') {
                available.push(i);
            } else if (s[i] == '(') {
                open.push(i);
            } else {
                if(open.empty() == false) {
                    open.pop();
                } else if(available.empty() == false) {
                    available.pop();
                } else {
                    return false;
                }
            }
        }
        
        while(open.empty() == false && available.empty() == false) {
            if(open.top() > available.top()) {
                return false;
            }

            open.pop();
            available.pop();
        }

        return open.empty();
    }
};

int main(void) {
    Solution s;
    string input  = "((()(()()))()((()()))))()((()(()";
    string locked = "10111100100101001110100010001001";

    // input = "(((()))()((()()))))()((()(()"
    //locked = "1011000101001110100010001001"

    cout << "Ans: " << s.canBeValid(input, locked) << endl;

    string input2  = "())()))()(()(((())(()()))))((((()())(())";
    string locked2 = "1011101100010001001011000000110010100101";

    // string input2  = "()(())";
    // string locked2 = "000101";

    // "())())"
    // "101000"

    cout << "Ans: " << s.canBeValid(input2, locked2) << endl;

    return 0;
}