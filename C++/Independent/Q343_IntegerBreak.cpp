#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        if(n > 2)
            dp[3] = 2;
        for(int i = 4; i <= n; i++){
            int maxN = 0;
            for(int j = 2; j < i; j++){
                int pair = i - j;
                if(pair < j)
                    break;
                else
                    maxN = std::max(std::max(dp[j], j) * std::max(dp[pair], pair), maxN);
            }
            dp[i] = maxN;
        }
        return dp[n];
    }
};

int main(void){
    int m = 2;
    int n = 10;
    Solution s;
    for(int i = m; i <= n; i++)
        cout << i << ": " << s.integerBreak(i) << endl;

    return 0;
}