#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int> >& redEdges, vector<vector<int> >& blueEdges) {
        vector<int> ans(n, -1);
        for(int check = 0; check < 2; check++){
            vector<vector<int> > redTable(n, vector<int>());
            vector<vector<int> > blueTable(n, vector<int>());
            for(int i = 0; i < redEdges.size(); i++)
                redTable[redEdges[i][0]].push_back(redEdges[i][1]);
            for(int i = 0; i < blueEdges.size(); i++)
                blueTable[blueEdges[i][0]].push_back(blueEdges[i][1]);

            queue<int> bfs;
            bfs.push(0);
            int sameLevelCount = 1;
            int steps = 0;
            bool isRed = check == 0 ? true : false;
            while(!bfs.empty()){
                int point = bfs.front(); bfs.pop();
                if(ans[point] == -1 || steps < ans[point])
                    ans[point] = steps;

                if(isRed){
                    for(int i = 0; i < redTable[point].size(); i++){
                        if(redTable[point][i] ^ -1){
                            bfs.push(redTable[point][i]);
                            redTable[point][i] = -1;
                        }
                    }
                }
                else{
                    for(int i = 0; i < blueTable[point].size(); i++){
                        if(blueTable[point][i] ^ -1){
                            bfs.push(blueTable[point][i]);
                            blueTable[point][i] = -1;
                        }
                    }
                }

                sameLevelCount--;
                if(sameLevelCount == 0){
                    steps++;
                    sameLevelCount = bfs.size();
                    isRed = !isRed;
                }
            }
        }

        return ans;
    }
};

int main(void){
    vector<vector<int> > redEdges;
    vector<vector<int> > blueEdges;

    vector<int> edge;
    edge.push_back(0);
    edge.push_back(1);
    redEdges.push_back(edge);

    edge.clear();
    edge.push_back(3);
    edge.push_back(3);
    redEdges.push_back(edge);

    edge.clear();
    edge.push_back(1);
    edge.push_back(3);
    blueEdges.push_back(edge);

    edge.clear();
    edge.push_back(3);
    edge.push_back(3);
    blueEdges.push_back(edge);

    Solution s;
    vector<int> ans = s.shortestAlternatingPaths(4, redEdges, blueEdges);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}