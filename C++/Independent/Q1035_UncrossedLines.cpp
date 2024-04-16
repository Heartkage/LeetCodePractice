#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int y = i + 1;
                int x = j + 1;
                if(nums1[i] == nums2[j]){
                    dp[y][x] = max(dp[y-1][x], max(dp[y-1][x-1] + 1, dp[y][x-1]));
                }
                else{
                    dp[y][x] = max(dp[y-1][x], dp[y][x-1]);
                }
                //printMap(dp);
            }
        }
        return dp[n][m];
    }

    void printMap(vector<vector<int> > dp){
        for(int i = 0; i < dp.size(); i++){
            for(int j = 0; j < dp[i].size(); j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(void){
    vector<int> nums1;
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(5);

    vector<int> nums2;
    nums2.push_back(10);
    nums2.push_back(5);
    nums2.push_back(2);
    nums2.push_back(1);
    nums2.push_back(5);
    nums2.push_back(2);

    Solution s;
    cout << s.maxUncrossedLines(nums2, nums1) << endl;

    return 0;
}