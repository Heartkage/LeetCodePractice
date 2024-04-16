#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int longestLength = 0;
        int startIndex = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            bool oddStop = false;
            bool evenStop = false;
            for(int l = i, r = i; l >= 0 && r < n; l--, r++){
                if(!evenStop && (r+1) < n && s[l] == s[r+1]){
                    int newLength = (r+1) - l + 1;
                    if(newLength > longestLength){
                        longestLength = newLength;
                        startIndex = l;
                    }

                    if(s[l] != s[r])
                        oddStop = true;
                }
                else if(!oddStop && s[l] == s[r]){
                    evenStop = true;
                    int newLength = r - l + 1;
                    if(newLength > longestLength){
                        longestLength = newLength;
                        startIndex = l;
                    }
                }
                else
                    break;
            }
        }
        return s.substr(startIndex, longestLength);
    }
};

int main(void){
    Solution s;
    cout << s.longestPalindrome("32101232100123") << endl;
    return 0;
}