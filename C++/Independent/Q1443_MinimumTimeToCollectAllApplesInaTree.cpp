#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int> >& edges, vector<bool>& hasApple) {
        int edgeCount = 0;
        bool needToWalk[n];
        int walkedPath[n];
        memset(needToWalk, false, n);
        memset(walkedPath, -1, sizeof(int)*n);

        walkedPath[0] = 0;
        for(int i = 0; i < edges.size(); i++){
            int prePoint = (walkedPath[edges[i][0]] > -1) ? edges[i][0] : edges[i][1];
            int point = (walkedPath[edges[i][0]] > -1) ? edges[i][1] : edges[i][0];

            walkedPath[point] = prePoint;
            needToWalk[point] = true;
            if(hasApple[point]){
                while(needToWalk[point]){
                    edgeCount++;
                    needToWalk[point] = false;
                    point = walkedPath[point];
                }
            }
        }
        return edgeCount*2;
    }
};

int main(void){
    vector<vector<int> > input;
    vector<int> edge;
    edge.push_back(0);
    edge.push_back(2);
    input.push_back(edge);

    edge.clear();
    edge.push_back(0);
    edge.push_back(3);
    input.push_back(edge);

    edge.clear();
    edge.push_back(2);
    edge.push_back(1);
    input.push_back(edge);

    // edge.clear();
    // edge.push_back(1);
    // edge.push_back(5);
    // input.push_back(edge);

    // edge.clear();
    // edge.push_back(2);
    // edge.push_back(3);
    // input.push_back(edge);

    // edge.clear();
    // edge.push_back(2);
    // edge.push_back(6);
    // input.push_back(edge);

    vector<bool> hasApple;
    hasApple.push_back(false);
    hasApple.push_back(true);
    hasApple.push_back(false);
    hasApple.push_back(false);
    // hasApple.push_back(true);
    // hasApple.push_back(true);
    // hasApple.push_back(false);
    Solution s;
    cout << s.minTime(7, input, hasApple) << endl;
}