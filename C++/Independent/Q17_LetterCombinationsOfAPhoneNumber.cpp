#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int total = 0;
        int n = digits.size();
        if(n > 0){
            total = 1;
            for(int i = 0; i < n; i++){
                if(digits[i] ^ 55 && digits[i] ^ 57)
                    total *= 3;
                else
                    total *= 4;
            }
        }
        string temp(n, '-');
        vector<string> ans(total, temp);
        short currentShift = total;
        for(int i = 0; i < n; i++){
            int divideCount = (digits[i]^55 && digits[i]^57) ? 3 : 4;
            currentShift /= divideCount;

            int counter = 0;
            int letterIndex = 0;
            for(int j = 0; j < total; j++){
                if(counter == currentShift){
                    letterIndex++;
                    counter = 0;
                }
                if(letterIndex == divideCount)
                    letterIndex = 0;

                if(digits[i] < '8')
                    ans[j][i] = ((digits[i]-50) * 3 + letterIndex) + 'a';
                else
                    ans[j][i] = ((digits[i]-50-1) * 3 + 4 + letterIndex) + 'a';
                counter++;
            }
        }
        return ans;
    }
};

int main(void){
    Solution s;
    vector<string> ans = s.letterCombinations("");
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}