#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if(n > 1){
            vector<short> character(26, -1);
            for(int i = 0; i < 26; i++)
                character[order[i]-97] = i;

            for(int i = 1; i < n; i++){
                int minN = min(words[i-1].size(), words[i].size());
                bool isLarger = false;
                for(int j = 0; j < minN; j++){
                    if(character[words[i][j]-97] > character[words[i-1][j]-97]){
                        isLarger = true;
                        break;
                    }
                    else if(character[words[i][j]-97] < character[words[i-1][j]-97])
                        return false;
                }
                if(!isLarger && words[i].size() < words[i-1].size())
                    return false;
            }
        }
        return true;
    }
};

int main(void){
    vector<string> words;
    words.push_back("hello");
    words.push_back("hell");

    Solution s;
    cout << s.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz") << endl;

    return 0;
}