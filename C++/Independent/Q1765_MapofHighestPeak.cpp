#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int, int>> bfs;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    bfs.push({i, j});
                }
            }
        }
        
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        vector<vector<int>> ans(m, vector<int>(n, 0));

        while(!bfs.empty()) {
            pair<int, int> point = bfs.front();
            bfs.pop();
            int currentY = point.first;
            int currentX = point.second;

            for(int i = 0; i < 4; i++) {
                int x = currentX + dirX[i];
                int y = currentY + dirY[i];

                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                else if(isWater[y][x] == 1)
                    continue;
                
                ans[y][x] = ans[currentY][currentX] + 1;
                isWater[y][x] = 1;
                bfs.push({y, x});
            }   
        }

        return ans;
    }
};

int main(void) {
    vector<vector<int>> map;
    vector<int> row1;
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(1);
    map.push_back(row1);

    vector<int> row2;
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(0);
    map.push_back(row2);

    vector<int> row3;
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    map.push_back(row3);

    Solution s;
    auto ans = s.highestPeak(map);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}