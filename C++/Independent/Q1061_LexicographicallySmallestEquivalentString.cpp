#include<iostream>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int chars[26];
        memset(chars, -1, sizeof(int)*26);
        for(int i = 0 ; i < s1.length(); i++){
            if(s1[i] ^ s2[i]){
                int bigIndex = (s1[i] > s2[i]) ? s1[i] - 'a' : s2[i] - 'a';
                int smallIndex = (s1[i] > s2[i]) ? s2[i] - 'a' : s1[i] - 'a';
                if(chars[bigIndex] == -1)
                    chars[bigIndex] = smallIndex;
                else{
                    while(chars[bigIndex] != -1)
                        bigIndex = chars[bigIndex];
                    while(chars[smallIndex] != -1)
                        smallIndex = chars[smallIndex];

                    if(bigIndex < smallIndex)
                        chars[smallIndex] = bigIndex;
                    else if(bigIndex > smallIndex)
                        chars[bigIndex] = smallIndex;
                }
            }
        }

        for(int i = 0; i < baseStr.length(); i++){
            int currentIndex = baseStr[i]-'a';
            while(chars[currentIndex] != -1){
                currentIndex = chars[currentIndex];
            }
            baseStr[i] = 'a' + currentIndex;
        }
        return baseStr;
    }
};

int main(void){
    Solution s;
    cout << s.smallestEquivalentString("leetcode", "programs", "sourcecode") << endl;
    return 0;
}