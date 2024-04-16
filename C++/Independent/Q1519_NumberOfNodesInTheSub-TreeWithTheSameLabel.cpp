#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void dfs(int point, vector<vector<int> > &tree, vector<int> &chars, string &labels, vector<int> &ans){
        chars[labels[point]-'a']++;
        for(int i = 0; i < tree[point].size(); i++){
            vector<int> output(26, 0);
            dfs(tree[point][i], tree, output, labels, ans);
            for(int j = 0; j < output.size(); j++){
                chars[j] += output[j];
            }
        }
        ans[point] = chars[labels[point]-'a'];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int> >& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int> > treeInVec(n, vector<int>());
        int path[n];
        memset(path, -1, sizeof(int)*n);
        path[0] = 0;
        for(int i = 0; i < edges.size(); i++){
            int prePoint = (path[edges[i][0]] > -1) ? edges[i][0] : edges[i][1];
            int point = (path[edges[i][0]] > -1) ? edges[i][1] : edges[i][0];
            path[point] = prePoint;
            treeInVec[prePoint].push_back(point);
        }
        vector<int> temp(26, 0);
        dfs(0, treeInVec, temp, labels, ans);
        return ans;
    }
};

int main(void){
    vector<vector<int> > edges;
    vector<int> edge;
    edge.push_back(0);
    edge.push_back(1);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(0);
    edge.push_back(2);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(1);
    edge.push_back(4);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(1);
    edge.push_back(5);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(2);
    edge.push_back(3);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(2);
    edge.push_back(6);
    edges.push_back(edge);

    Solution s;
    vector<int> ans = s.countSubTrees(7, edges, "abaedcd");
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " " << endl;
    }


    return 0;
}