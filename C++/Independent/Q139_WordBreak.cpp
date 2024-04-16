#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    void PrintTable(vector<bool> &table){
        for(auto value : table)
            cout << value << " ";
        cout << endl;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> table(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> check(n + 1, false);
        check[0] = true;
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < i; j++){
                if(check[j] == false)
                    continue;

                if(table.count(s.substr(j, i-j)) > 0){
                    check[i] = true;
                    break;
                }
            }
        }
        return check[n];
    }
};

int main(void){
    Solution s;
    vector<string> input;
    input.push_back("leet");
    input.push_back("code");
    input.push_back("a");
    cout << s.wordBreak("leetcodea", input) << endl;
    return 0;
}