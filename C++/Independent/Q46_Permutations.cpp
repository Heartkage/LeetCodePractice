#include<iostream>
#include<vector>
using namespace std;

class Solution {
    vector<int> result;
    vector<bool> table;
    void RecursiveSearch(vector<vector<int> > &ans, vector<int> &input){
        int n = input.size();
        if(result.size() == n){
            ans.push_back(result);
        }
        else{
            for(int i = 0; i < n; i++){
                if(table[i] == false){
                    table[i] = true;
                    result.push_back(input[i]);
                    RecursiveSearch(ans, input);
                    result.pop_back();
                    table[i] = false;
                }
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        table.clear();
        for(int i = 0; i < nums.size(); i++)
            table.push_back(false);
        RecursiveSearch(ans, nums);
        return ans;
    }
};

int main(void){
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    
    Solution s;
    auto ans = s.permute(input);
    for(int i = 0; i < ans.size(); i++){
        cout << "[";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}