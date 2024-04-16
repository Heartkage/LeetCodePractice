#include<iostream>

using namespace std;

class Solution {
    vector<int> temp;
    void RecursiveSearch(vector<vector<int> > &ans, int n, int index, int k){
        if(k == 0){
            ans.push_back(temp);
        }
        else{
            for(int i = index; i <= n; i++){
                temp.push_back(i);
                RecursiveSearch(ans, n, i + 1, k - 1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        RecursiveSearch(ans, n, 1, k);
        return ans;
    }
};


int main(void){
    Solution s;
    vector<vector<int> > output = s.combine(4, 2);

    for(int i = 0; i < output.size(); i++){
        cout << "[";
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}