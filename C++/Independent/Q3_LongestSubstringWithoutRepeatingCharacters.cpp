#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> character(128, -1);
        int n = s.length();
        int start = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(character[s[i]] >= start){
                ans = max(ans, i - start);
                start = character[s[i]] + 1;
            }
            character[s[i]] = i;
        }
        ans = max(ans, n - start);
        return ans;
    }
};

int main(void){
    Solution s;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    return 0;
}