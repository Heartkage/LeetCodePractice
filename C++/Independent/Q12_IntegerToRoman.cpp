#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> romanLetters;
        romanLetters.push_back("IVX");
        romanLetters.push_back("XLC");
        romanLetters.push_back("CDM");
        romanLetters.push_back("M");

        string ans;
        int counter = 0;
        while(num){
            int lastDigit = num%10;

            if(lastDigit == 9){
                ans.insert(ans.begin(), 1, romanLetters[counter][2]);
                ans.insert(ans.begin(), 1, romanLetters[counter][0]);
            }
            else if(lastDigit > 4){
                ans.insert(ans.begin(), lastDigit - 5, romanLetters[counter][0]);
                ans.insert(ans.begin(), 1, romanLetters[counter][1]);
            }
            else if(lastDigit == 4){
                ans.insert(ans.begin(), 1, romanLetters[counter][1]);
                ans.insert(ans.begin(), 1, romanLetters[counter][0]);
            }
            else if(lastDigit > 0){
                ans.insert(ans.begin(), lastDigit, romanLetters[counter][0]);
            }
            counter++;
            num /= 10;
        }
        return ans;
    }
};

int main(void){

    Solution s;
    cout << s.intToRoman(5) << endl;

    return 0;
}
