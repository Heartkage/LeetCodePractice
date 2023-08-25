#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if(n1 + n2 != n3)
            return false;

        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n1; i++){
            if(dp[i - 1][0] && s1[i - 1] == s3[i - 1])
                dp[i][0] = true;
        }        

        for(int i = 1; i <= n2; i++){
            if(dp[0][i - 1] && s2[i - 1] == s3[i - 1])
                dp[0][i] = true;
        }

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
                else if(dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }
        return dp[n1][n2];
    }
};

int main(void){
    Solution s;

    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    return 0;
}