#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return false;

        bool isOdd = false;
        isOdd = nums[0] & 1;

        for(int i = 1; i < n; i++){
            if((nums[i-1] ^ nums[i]) & 1)
                continue;
            else
                return false;
        }
        return true;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = 1;
        for(int i = 1; i < n; i++){
            if((nums[i-1] ^ nums[i]) & 1)
                dp[i] = dp[i-1] + 1;
            else
                dp[i] = 1;
        }

        int m = queries.size();
        vector<bool> ans(m, false);
        for(int i = 0; i < m; i++){
            int l = queries[i][1] - queries[i][0] + 1;
            if(dp[queries[i][1]] >= l)
                ans[i] = true;
        }

        return ans;
    }

    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        while(nums[0]){
            vector<int> table(10, 0);
            for(int i = 0; i < n; i++){
                table[nums[i] % 10]++;
                nums[i] /= 10;
            }

            long long total = n;
            for(int i = 0; i < table.size(); i++){
                if(table[i] == 0)
                    continue;
                
                total -= table[i];
                ans += total*table[i];
            }
        }

        return ans;
    }

    int recursiveSearch(int k, long long current, int jump, bool lastIsStepDown){
        if((current - 1) > k)
            return 0;
        
        int ans = (current == k) ? 1 : 0;

        if(lastIsStepDown || current == 0)
            return recursiveSearch(k, current + pow(2, jump), jump+1, false) + ans;
        else
            return recursiveSearch(k, current - 1, jump, true) + recursiveSearch(k, current + pow(2, jump), jump+1, false) + ans;
    }
    int waysToReachStair(int k) {
        return recursiveSearch(k, 1, 0, false);
    }
};

int main(void){
    cout << "Testing: WeeklyContest-398" << endl;
    vector<int> n;
    n.push_back(50);
    n.push_back(28);
    n.push_back(48);

    Solution s;
    cout << s.isArraySpecial(n) << endl;

    cout << s.sumDigitDifferences(n) << endl;

    cout << s.waysToReachStair(384813228) << endl;
    return 0;
}