#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        short m = needle.size();
        vector<short> table(m, 0);
        for(int i = 1; i < m; i++){
            if(table[i - 1] > 0){
                if(needle[i] == needle[table[i - 1]])
                    table[i] = table[i - 1] + 1;
                else if(needle[table[table[i - 1] - 1]] == needle[i])
                    table[i] = table[table[i - 1] - 1] + 1;
            }
            else if(needle[i] == needle[0]){
                table[i] = 1;
            }
        }

        // for(int i = 0; i < m; i++)
        //     cout << table[i] << ", ";
        // cout << endl;

        short checkIndex = 0;
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[checkIndex]){
                checkIndex++;
                if(checkIndex == m)
                    return i - (m - 1);
            }
            else if(checkIndex > 0){
                checkIndex = table[checkIndex - 1];
                i--;
            }
        }

        return -1;
    }
};

int main(void){
    Solution s;
    cout << s.strStr("mississippi", "adcadde") << endl;
    return 0;
}