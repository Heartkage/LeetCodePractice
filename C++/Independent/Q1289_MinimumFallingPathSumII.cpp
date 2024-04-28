#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int recursionSearch(vector<vector<int>> &grid, vector<vector<int>> &map, int row, int lastColumn, int n){
        int minValue = INT_MAX;
        for(int i = 0; i < n; i++){
            if(lastColumn == i)
                continue;
            
            if(row < n){
                if(map[row][i] == INT_MIN){
                    map[row][i] = recursionSearch(grid, map, row+1, i, n) + grid[row][i];
                }
                minValue = min(minValue, map[row][i]);
            }
        }
        return minValue == INT_MAX ? 0 : minValue;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> map(n, vector<int>(n, INT_MIN));
        return recursionSearch(grid, map, 0, -1, n);
    }
};

int main(void){
    vector<vector<int>> grid;
    vector<int> row;
    row.push_back(1);
    row.push_back(4);
    row.push_back(3);
    grid.push_back(row);

    row.clear();
    row.push_back(2);
    row.push_back(8);
    row.push_back(5);
    grid.push_back(row);

    row.clear();
    row.push_back(7);
    row.push_back(6);
    row.push_back(9);
    grid.push_back(row);

    Solution s;
    cout << s.minFallingPathSum(grid) << endl;
    return 0;
}