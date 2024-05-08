#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<string> ans(n);
        map<int, int> table;

        for(int i = 0; i < n; i++)
            table.insert(pair<int, int>(score[i], i));

        sort(score.begin(), score.end(), greater<int>());

        for(int i = 0; i < n; i++){
            int index = table[score[i]];
            switch (i)
            {
            case 0:
                ans[index] = "Gold Medal";
                break;
            case 1:
                ans[index] = "Silver Medal";
                break;
            case 2:
                ans[index] = "Bronze Medal";
                break;
            default:
                ans[index] = to_string(i + 1);
                break;
            }
        }
        return ans;
    }
};

int main(void){
    vector<int> score;
    score.push_back(1);
    score.push_back(2);
    score.push_back(3);
    score.push_back(4);
    score.push_back(5);

    Solution s;
    auto ans = s.findRelativeRanks(score);
    for(auto o : ans){
        cout << o << endl;
    }
    return 0;
}