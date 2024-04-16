#include<iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int table[26];
        fill(begin(table), end(table), 100001);
        for(int i=0; i < s.length(); i++){
            if(table[s[i]-'a'] == 100001)
                table[s[i]-'a'] = i;
            else
                table[s[i]-'a'] = 100002;
        }
        int minIndex = 100001;
        for(int i = 0; i < 26; i++){
            if(table[i] < minIndex)
                minIndex = table[i];
        }

        return (minIndex == 100001) ? -1 : minIndex;
    }
};

int main(void){
    Solution s;
    cout << s.firstUniqChar("loveleetcode") << endl;
    return 0;
}