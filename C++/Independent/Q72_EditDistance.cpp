#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word1[i] == word2[j])
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = min(dp[i+1][j], min(dp[i][j+1], dp[i][j])) + 1;
            }
        }
        return dp[n][m];
    }
};

int main(void){
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
    return 0;
}