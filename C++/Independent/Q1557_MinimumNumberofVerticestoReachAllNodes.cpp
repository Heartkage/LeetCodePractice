#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void RecursiveSearch(int index, vector<vector<int> > &graph, vector<int> &check){
        if(check[index] ^ -1)
            return;
        
        for(int i = 0; i < graph[index].size(); i++){
            RecursiveSearch(graph[index][i], graph, check);
            check[graph[index][i]] = index;
        }
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int> >& edges) {
        vector<int> check(n, -1);
        vector<vector<int> > graph(n, vector<int>());
        for(int i = 0; i < edges.size(); i++)
            graph[edges[i][0]].push_back(edges[i][1]);
        
        for(int i = 0; i < graph.size(); i++)
            RecursiveSearch(i, graph, check);

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(check[i] == -1)
                ans.push_back(i);
        }
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
    edge.push_back(2);
    edge.push_back(5);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(3);
    edge.push_back(4);
    edges.push_back(edge);

    edge.clear();
    edge.push_back(4);
    edge.push_back(2);
    edges.push_back(edge);

    Solution s;
    vector<int> ans = s.findSmallestSetOfVertices(6, edges);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}