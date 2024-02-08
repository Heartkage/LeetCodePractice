#include<iostream>
using namespace std;

//           0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//        1  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//        4  0 1 2 3 1 2 3 4 2 3 4  5  3  4  5  6  4
//        9  0 1 2 3 1 2 3 4 2 1 2  3  3  2
//        16

class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);

        int dp[n+1];
        for(int i = 1; i <= n; i++)
            dp[i] = i;

        for(int i = 2; i <= m; i++){
            for(int j = i*i; j <= n; j++){
                int s = i*i;
                int remainder = j % s;
                int result = j / s;

                dp[j] = min(dp[j], result + dp[remainder]);
            }
            cout << dp[196] << endl;
        }

        return dp[n];
    }
};

int main(void){
    Solution s;
    cout << s.numSquares(196) << endl;
    return 0;
}