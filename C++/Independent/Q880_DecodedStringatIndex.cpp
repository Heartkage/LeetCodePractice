#include<iostream>
#include<stack>
using namespace std;

class Solution {
    struct wordGroup{
        int amount;
        int letterIndex;
        wordGroup(int a, int i = -1) : amount(a), letterIndex(i){}
    };

    bool isDigit(char c){
        return (c >= '0' && c <= '9');
    }
public:
    string decodeAtIndex(string s, int k) {
        stack<wordGroup> nums;
        nums.push(wordGroup(0));
        nums.push(wordGroup(1));
        bool lastIsDigit = true;
        int letterCount = 0;
        int val = 0;

        // Part 1: building stack numbers
        for(int i = 0; i < s.length(); i++){
            if(isDigit(s[i])){
                int n = s[i] - '0';
                if(lastIsDigit){
                    int top = nums.top().amount;
                    val /= top;
                    n *= top;
                    nums.pop();
                }
                else{
                    nums.push(wordGroup(letterCount, i - letterCount));
                    letterCount = 0;
                }
                nums.push(wordGroup(n));
                val *= n;
                lastIsDigit = true;
                if(k <= val)
                    break;
            }
            else{
                letterCount++;
                val++;
                lastIsDigit = false;
                if(val == k){
                    string ans(1, s[i]);
                    return ans;
                }
            }
        }

        // Part 2: finding right mod
        int modResult = k;
        while(!nums.empty()){
            val /= nums.top().amount;
            nums.pop();

            modResult %= val;
            if(modResult == 0)
                modResult = val;
            
            wordGroup previousLetter = nums.top();
            if(modResult > (val - previousLetter.amount)){
                int index = (modResult - (val - previousLetter.amount)) % previousLetter.amount;
                if(index == 0)
                    index = previousLetter.amount;
                index = previousLetter.letterIndex + index - 1;
                string ans(1, s[index]);
                return ans;
            }
            else{
                val -= previousLetter.amount;
                nums.pop();
            }
        }
        return "";
    }
};

int main(void){
    Solution s;
    cout << s.decodeAtIndex("a4vsb832i3zxouzx6vu6", 31179) << endl;
    return 0;
}