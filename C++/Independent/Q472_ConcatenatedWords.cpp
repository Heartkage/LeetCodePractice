#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_set<string> set;
        for(int i = 0; i < words.size(); i++)
            set.insert(words[i]);

        for(int i = 0; i < words.size(); i++){
            int n = words[i].size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for(int j = 0; j < n; j++){
                if(!dp[j])
                    continue;
                for(int k = j + 1; k <= n && k-j < n; k++){
                    if(set.count(words[i].substr(j, k-j)))
                        dp[k] = true;
                }

                if(dp[n])
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(void){
    vector<string> words;
    words.push_back("cat");
    words.push_back("cats");
    words.push_back("catsdogcats");
    words.push_back("dog");
    words.push_back("dogcatsdog");
    words.push_back("hippopotamuses");
    words.push_back("rat");
    words.push_back("ratcatdogcat");

    Solution s;
    vector<string> ans = s.findAllConcatenatedWordsInADict(words);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    // cout << words[0].substr(0, 3) << endl;
    return 0;
}