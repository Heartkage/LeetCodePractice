#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> map2;
        int j = 0;
        for(int i = 0; i < pattern.length(); i++){
            int start = j;
            for(; j < s.length(); j++){
                if(s[j] == ' ')
                    break;
            }
            string sub;
            if(j <= s.length()){
                sub = s.substr(start, j-start);
                j++;
            }
            else{
                return false;
            }

            if(map.find(pattern[i]) != map.end()){
                if(map[pattern[i]].compare(sub) != 0)
                    return false;
            }
            else if(map2.find(sub) != map2.end()){
                if(map2[sub] != pattern[i])
                    return false;
            }
            else{
                map.insert(pair<char, string>(pattern[i], sub));
                map2.insert(pair<string, char>(sub, pattern[i]));
            }
        }

        if(j < s.length())
            return false;
        else
            return true;
    }
};

int main(void){
    Solution s;
    cout << s.wordPattern("ab", "dog") << endl;
    return 0;
}