#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<short> table(26);
        int n = s.length();
        int highestIndex = 0;
        for(int i = 0; i < n; i++){
            int index = s[i]-'a';
            table[index]++;
            if((table[index] * 2) > n + 1)
                return "";
            else if(table[index] > table[highestIndex])
                highestIndex = index;
        }
        
        int index = highestIndex;
        string ans(n, '\0');
        for(int i = 0; i < n; i+=2){
            while(table[index] == 0)
                index = (index + 1) % 26;
            ans[i] = 'a' + index;
            table[index]--;
            if(table[index] == 0)
                i--;
        }
        
        for(int i = 0; i < n; i++){
            if(ans[i] != '\0')
                continue;
            while(table[index] == 0)
                index = (index + 1) % 26;
            ans[i] = 'a' + index;
            table[index]--;
        }
        return ans;
    }
};

int main(void){
    Solution s;
    cout << s.reorganizeString("aaaaabbbb") << endl;
    return 0;
}