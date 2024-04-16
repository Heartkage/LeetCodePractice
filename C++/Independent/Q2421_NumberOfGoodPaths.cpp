#include<iostream>
#include<vector>
#include<map>
using namespace std; 

class Solution {
    int CommutationOf2(int n){
        if(n < 2)
            return n;
        else
            return (n*(n-1) / 2) + n;
    }
    void Recursion(int node, int lastVal, vector<vector<int> > &graph, vector<int> &vals, map<int, int> &counter, int *ans){
        map<int, int> temp;
        for(int i = 0; i < graph[node].size(); i++){
            Recursion(graph[node][i], vals[node], graph, vals, temp, ans);
        }

        if(temp.find(vals[node]) == temp.end())
            temp.insert(pair<int, int>(vals[node], 1));
        else
            temp[vals[node]]++;

        for(map<int, int>::iterator it = temp.begin(); it != temp.end(); it++){
            if(lastVal == -1){
                (*ans) += CommutationOf2(it->second);
            }
            else if(it->first < lastVal){
                (*ans) += CommutationOf2(it->second);
            }
            else{
                if(counter.find(it->first) == counter.end())
                    counter.insert(pair<int, int>(it->first, it->second));
                else
                    counter[it->first] += it->second;
            }
        }
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int> >& edges) {
        int *ans = new int(0);

        int n = vals.size();
        vector<vector<int> > graph(n);
        bool check[n];
        memset(check, 0, n);

        check[0] = true;
        for(int i = 0; i < edges.size(); i++){
            if(check[edges[i][0]]){
                graph[edges[i][0]].push_back(edges[i][1]);
                check[edges[i][1]] = true;
            }
            else{
                graph[edges[i][1]].push_back(edges[i][0]);
                check[edges[i][0]] = true;
            }
        }

        map<int, int> counter;
        Recursion(0, -1, graph, vals, counter, ans);
        return (*ans);
    }
};

int main(void){
    vector<int> vals;
    // vals.push_back(1);
    // vals.push_back(1);
    vals.push_back(2);
    vals.push_back(2);
    vals.push_back(5);
    vals.push_back(5);

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
    edge.push_back(0);
    edge.push_back(3);
    edges.push_back(edge);

    // edge.clear();
    // edge.push_back(2);
    // edge.push_back(4);
    // edges.push_back(edge);

    Solution s;
    cout << s.numberOfGoodPaths(vals, edges) << endl;

    return 0;
}