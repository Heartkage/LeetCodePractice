#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(k > n) 
            return false;

        vector<int> table(26, 0);
        for(int i = 0; i<n; i++) {
            table[s[i]-'a']++;
        }
        
        int minimumK = 0;
        for(int i = 0; i < 26; i++) {
            if(table[i] & 1) {
                minimumK++;
            }
        }
        
        return k >= minimumK;
    }
};

int main(void) {
    Solution s;
    string a = "annabelle";
    int k = 10;
    for(int i = 1; i<=k; i++) {
        cout << "s: " << a << ", k: " << i << " = " << s.canConstruct(a, i) << endl;
    }
    return 0;
}