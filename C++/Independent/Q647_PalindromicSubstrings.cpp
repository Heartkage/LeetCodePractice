#include<iostream>
using namespace std;

//   a a a
// 0 1 1 1
// 1 0 1 1
// 2 0 0 1

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<int> tmp(n, 0);
        vector<vector<int>> dp(n, tmp);

        for(int i = 0; i < n; i++)
            dp[0][i] = 1;

        for(int i = 1; i < n; i++){
            for(int j = i; j < n; j++){
                if(s[j] == s[j-i]){
                    if(i > 1){
                        if(dp[i-2][j-1] == 1)
                            dp[i][j] = 1;
                    }
                    else
                        dp[i][j] = 1;
                }
            }
        }
        
        int total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                total += dp[i][j];
        }
        return total;
    }
};

int main(void){
    Solution s;
    cout << s.countSubstrings("abcba") << endl;
    return 0;
}