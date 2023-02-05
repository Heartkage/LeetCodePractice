#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<short> character(26, -1);
        int n = p.size();
        for(int i = 0; i < n; i++){
            if(character[p[i]-'a'] < 0)
                character[p[i]-'a'] = 0;
            character[p[i]-'a']++;
        }
            
        vector<int> res;
        int counter = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(character[s[i]-'a'] > 0){
                if(counter == 0)
                    start = i;
                character[s[i]-'a']--;
                counter++;
            }
            else if(character[s[i]-'a'] > -1){
                int total = start+counter;
                for(int j = start; j < total; j++){
                    if(s[j] != s[i]){
                        character[s[j]-'a']++;
                        counter--;
                    }
                    else{
                        start = j + 1;
                        break;
                    }
                }
            }
            else{
                for(int j = start; j < start + counter; j++)
                    character[s[j]-'a']++;
                counter = 0;
            }

            if(counter == n){
                res.push_back(start);
                character[s[start]-'a']++;
                counter--;
                start++;
            }
        }
        return res;
    }
};

int main(void){
    Solution s;
    vector<int> ans = s.findAnagrams("aecbabedce", "a");
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}