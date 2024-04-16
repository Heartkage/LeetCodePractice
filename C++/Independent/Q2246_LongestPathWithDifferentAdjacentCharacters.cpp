#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
    int dfs(int index, vector<vector<int> > &table, string &s, int *ans){
        int max1 = 0;
        int max2 = 0;
        for(int i = 0 ; i < table[index].size(); i++){
            int childLongestPath = dfs(table[index][i], table, s, ans);

            if(s[index] ^ s[table[index][i]]){
                if(childLongestPath > max1){
                    max2 = max1;
                    max1 = childLongestPath;
                }
                else if(childLongestPath > max2)
                    max2 = childLongestPath;
            }
        }
        (*ans) = max(*ans, max1 + 1 + max2);
        return max1 + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int> > table(n);
        for(int i = 1; i < n; i++){
            table[parent[i]].push_back(i);
        }
        int *ans =  new int(0);
        dfs(0, table, s, ans);
        return (*ans);
    }
};

int main(void){

    vector<int> nodes;
    nodes.push_back(-1);
    nodes.push_back(0);
    nodes.push_back(0);
    nodes.push_back(1);
    nodes.push_back(1);
    nodes.push_back(2);
    Solution s;
    cout << s.longestPath(nodes, "abacbe") << endl;

    return 0;
}