#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        const int englishLetterCount = 26;
        vector<set<string> > table(englishLetterCount, set<string>());
        for(int i = 0; i < ideas.size(); i++){
            table[ideas[i][0]-'a'].insert(ideas[i].substr(1));
        }
        
        long long ans = 0;
        for(int i = 0; i < englishLetterCount; i++){
            for(int j = i + 1; j < englishLetterCount; j++){
                int similarCount = 0;
                for(set<string>::iterator it = table[i].begin(); it != table[i].end(); it++){
                    if(table[j].count(*it) > 0)
                        similarCount++;
                }
                ans += 2 * (table[i].size() - similarCount) * (table[j].size() - similarCount);
            }
        }
        return ans;
    }
};


int main(void){
    vector<string> ideas;
    ideas.push_back("dogs");
    ideas.push_back("donuts");
    ideas.push_back("time");
    ideas.push_back("togs");
    ideas.push_back("lime");
    ideas.push_back("logs");

    Solution s;
    cout << s.distinctNames(ideas) << endl;
    return 0;
}