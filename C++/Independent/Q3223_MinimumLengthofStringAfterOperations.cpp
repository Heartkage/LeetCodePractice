#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> table(26, 0);
        int n = s.length();
        for(int i=0; i<n; i++) {
            table[s[i]-'a']++;
        }

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(table[i] == 0)
                continue;
                
            if(table[i] & 1)
                ans += 1;
            else
                ans += 2;
        }
        return ans;
    }
};

int main(void){
    Solution s;
    cout << "Ans: " << s.minimumLength("abaacbcbb") << endl;
    return 0;
}