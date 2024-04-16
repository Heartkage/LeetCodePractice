#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int ans;
    int xMax;
    int yMax;
    int xDir[4];
    int yDir[4];
    int walkCount;

    void dfs(vector<vector<int> > &grid, bool **walked, int x, int y){
        //printf("%d\n", walkCount);
        if((x < 0) || (x >= xMax) || (y < 0) || (y >= yMax))
            return;
        else if(walked[y][x] == true)
            return;
        else if(grid[y][x] == 2 && walkCount == 0)
            ans++;
        else if(grid[y][x] == 0 || grid[y][x] == 1){
            for(int i = 0 ; i < 4; i++){
                walked[y][x] = true;
                walkCount--;
                dfs(grid, walked, x + xDir[i], y + yDir[i]);
                walkCount++;
                walked[y][x] = false;
            }
        }
    }

public:
    Solution(){
        xDir[0] = 1;
        yDir[0] = 0;

        xDir[1] = 0;
        yDir[1] = 1;

        xDir[2] = -1;
        yDir[2] = 0;

        xDir[3] = 0;
        yDir[3] = -1;
    }

    int uniquePathsIII(vector<vector<int> >& grid) {
        ans = 0;
        yMax = grid.size();
        xMax = grid[0].size();
        walkCount = 0;

        int startX;
        int startY;
        bool **walked = new bool*[yMax];
        for(int i = 0; i < yMax; i++){
            walked[i] = new bool[xMax];
            for(int j = 0; j < xMax; j++){
                walked[i][j] = false;
                switch (grid[i][j])
                {
                case 0:
                    walkCount++;
                    break;
                case 1:
                    walkCount++;
                    startX = j;
                    startY = i;
                    break;
                default:
                    break;
                }
            }
        }

        dfs(grid, walked, startX, startY);
        return ans;
    }
};

int main(void){
    vector<vector<int> > map;
    vector<int> row;
    row.push_back(1);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    map.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    map.push_back(row);

    row.clear();
    row.push_back(0);
    row.push_back(0);
    row.push_back(2);
    row.push_back(-1);
    map.push_back(row);

    Solution s;
    cout << s.uniquePathsIII(map) << endl;
    return 0;
}