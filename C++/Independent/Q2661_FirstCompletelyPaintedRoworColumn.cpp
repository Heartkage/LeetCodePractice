#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> table;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                table[mat[i][j]] = {i, j};
                // cout << "table: " << mat[i][j] << ", i = " << i << ", j = " << j << endl;
            }
        }

        vector<int> row(m, 0);
        vector<int> column(n, 0);

        for(int i = 0; i < arr.size(); i++) {
            const auto& point = table[arr[i]];
            int y = point.first;
            int x = point.second;
            // cout << "y: " << y << ", x: " << x << endl;
            row[y]++;
            column[x]++;

            if(column[x] == m || row[y] == n)
                return i;
        }

        return -1;
    }
};

int main(void) {

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(3);

    vector<vector<int>> mat(2, vector<int>(3, 0));
    mat[0][0] = 4;
    mat[0][1] = 3;
    mat[0][2] = 5;
    mat[1][0] = 1;
    mat[1][1] = 2;
    mat[1][2] = 6;
    
    Solution s;
    cout << "ans: " << s.firstCompleteIndex(arr, mat) << endl;

    return 0;
}