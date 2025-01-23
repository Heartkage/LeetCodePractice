#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int, int>>> row(m);
        vector<vector<pair<int, int>>> column(n);

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(row[i].size() == 0) {
                        grid[i][j] = 0;
                    } else {
                        pair<int, int> lastPoint = row[i][row[i].size()-1];
                        if(grid[lastPoint.first][lastPoint.second] == 0) {
                            grid[lastPoint.first][lastPoint.second] = 1;
                            ans += 2;
                        } else {
                            ans += 1;
                        }
                        grid[i][j] = 1;
                    }
                    row[i].push_back({i, j});

                    if(column[j].size() > 0) {
                        pair<int, int> lastPoint = column[j][column[j].size()-1];
                        if(grid[lastPoint.first][lastPoint.second] == 0) {
                            grid[lastPoint.first][lastPoint.second] = 1;
                            if(grid[i][j] == 0){
                                ans += 2;
                            } else {
                                ans += 1;
                            }
                        } else {
                            if(grid[i][j] == 0) {
                                ans += 1;
                            }
                        }
                        grid[i][j] = 1;
                    }
                    column[j].push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};

int main(void){
    vector<vector<int>> grid;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(1);
    row1.push_back(0);
    row1.push_back(1);
    grid.push_back(row1);

    vector<int> row2;
    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(0);
    grid.push_back(row2);

    vector<int> row3;
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(1);
    row3.push_back(0);
    grid.push_back(row3);

    vector<int> row4;
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(1);
    grid.push_back(row4);

    grid.push_back(row3);
    grid.push_back(row4);

    Solution s;
    cout << "ans: " << s.countServers(grid) << endl;

    return 0;
}