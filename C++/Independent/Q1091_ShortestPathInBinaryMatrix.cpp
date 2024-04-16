#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    bool isInsideGrid( int x, int y, int n){
        if(y < 0 || x < 0 || y >= n || x >= n)
            return false;
        else
            return true;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int> >& grid) {
        int n = grid.size();
        int goalPoint = n-1;
        vector<vector<int> > route(n, vector<int>(n, -1));
        queue<pair<int, int> > possibleRoute;

        if(grid[0][0] == 0){
            possibleRoute.push(pair<int, int>(0, 0));
            route[0][0] = 1;
        }

        int dirX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dirY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

        while(!possibleRoute.empty()){
            pair<int, int> point = possibleRoute.front();
            possibleRoute.pop();
            if(point.first == goalPoint && point.second == goalPoint)
                break;

            for(int i = 0; i < 8; i++){
                int nextX = point.first + dirX[i];
                int nextY = point.second + dirY[i];
                if(isInsideGrid(nextX, nextY, n)){
                    if(grid[nextY][nextX] == 0 && route[nextY][nextX] < 1){
                        route[nextY][nextX] = route[point.second][point.first] + 1;
                        possibleRoute.push(pair<int, int>(nextX, nextY));
                    }
                }
            }
        }

        return route[goalPoint][goalPoint];
    }
};

int main(void){
    vector<vector<int> > map;
    vector<int> row;
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    map.push_back(row);

    row.clear();
    row.push_back(1);
    row.push_back(1);
    row.push_back(0);
    map.push_back(row);

    row.clear();
    row.push_back(1);
    row.push_back(1);
    row.push_back(0);
    map.push_back(row);

    Solution s;
    cout << s.shortestPathBinaryMatrix(map) << endl;
}