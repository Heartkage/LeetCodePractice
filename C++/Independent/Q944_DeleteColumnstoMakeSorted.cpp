#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleteCount = 0;
        int n = strs[0].size();
        int m = strs.size();
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(strs[j][i] < strs[j-1][i]){
                    deleteCount++;
                    break;
                }
            }
        }
        return deleteCount;
    }
};

int main(void){
    vector<string> strs;
    strs.push_back("cba");
    strs.push_back("daf");
    strs.push_back("ghi");
    Solution s;
    cout << s.minDeletionSize(strs) << endl;
    return 0;
}