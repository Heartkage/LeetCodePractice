#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    void printGrid(vector<vector<int> > grid){
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
    int x_dir[4];
    int y_dir[4];
public:
    Solution(){
        x_dir[0] = -1;
        x_dir[1] = 0;
        x_dir[2] = 1;
        x_dir[3] = 0;

        y_dir[0] = 0;
        y_dir[1] = -1;
        y_dir[2] = 0;
        y_dir[3] = 1;

    }
    int maxDistance(vector<vector<int> >& grid) {
        queue<pair<int, int> > bfs;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            grid[i].insert(grid[i].begin(), -1);
            grid[i].push_back(-1);
        }
        vector<int> extraRow(n+2, -1);
        grid.insert(grid.begin(), extraRow);
        grid.push_back(extraRow);

        n = grid.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = -1;
                    bfs.push(pair<int, int>(i, j));
                }
            }
        }

        int ans = -1;
        while(!bfs.empty()){
            pair<int, int> location = bfs.front();
            bfs.pop();
            for(int i = 0; i < 4; i++){
                int nextY = location.first + y_dir[i];
                int nextX = location.second + x_dir[i];
                if(grid[nextY][nextX] == 0){
                    int step = grid[location.first][location.second] == -1 ? 1 : grid[location.first][location.second] + 1;
                    grid[nextY][nextX] = step;
                    ans = max(ans, step);
                    bfs.push(pair<int, int>(nextY, nextX));
                }
            }
        }
        //printGrid(grid);
        return ans;
    }
};

int main(void){
    vector<vector<int> > grid;
    vector<int> row;
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    grid.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    grid.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    grid.push_back(row);


    Solution s;
    cout << s.maxDistance(grid) << endl;
    return 0;
}