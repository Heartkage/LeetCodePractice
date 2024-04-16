#include<iostream>
#include<vector>
using namespace std;

class Solution {
    static bool pairCompare(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first ^ b.first)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
    void print(vector<pair<int, int> > &data){
        for(int i = 0; i < data.size(); i++)
            cout << data[i].first << ", " << data[i].second << endl;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int> > ageWithScore(n, pair<int, int>(0, 0));
        for(int i = 0; i < n; i++){
            ageWithScore[i].first = ages[i];
            ageWithScore[i].second = scores[i];
        }
        sort(ageWithScore.begin(), ageWithScore.end(), pairCompare);
        //print(ageWithScore);

        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i] = ageWithScore[i].second;
            for(int j = i - 1; j > -1; j--){
                if(ageWithScore[i].second >= ageWithScore[j].second)
                    dp[i] = max(dp[i], dp[j] + ageWithScore[i].second); 
            }
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};

int main(void){
    vector<int> scores;
    scores.push_back(897);
    scores.push_back(622);
    scores.push_back(299);
    scores.push_back(536);
    scores.push_back(797);

    vector<int> ages;
    ages.push_back(60);
    ages.push_back(79);
    ages.push_back(28);
    ages.push_back(33);
    ages.push_back(96);

    Solution s;
    cout << s.bestTeamScore(scores, ages) << endl;

    return 0;
}