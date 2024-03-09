#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
using namespace std;

class Solution {
    bool isY(int x, int y, int n){
        int mid = n/2;
        if(x == y & x <= mid) // top-left diagonal to center
            return true;
        else if(x == mid && y > mid) // Y, the bottom part
            return true;
        else if((n-1-x) == y && x > mid) // top-right diagonal to center
            return true;
        else
            return false;
    }
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[1]);
        int index = 0;
        int index2 = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[index] > temp[index2]){
                index++;
                nums[index] = nums[i];
            }
            else{
                index2++;
                temp.push_back(nums[i]);
            }
        }
        index2 = 0;
        for(int i = index + 1; i < nums.size(); i++){
            nums[i] = temp[index2];
            index2++;
        }
        return nums;
    }

    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int total = 0;
        for(int i = 0; i < grid.size(); i++){
            int rowTotal = 0;
            for(int j = 0; j < grid[i].size(); j++){
                rowTotal += grid[i][j];
                int sum = 0;
                if(i > 0)
                    sum = grid[i-1][j] + rowTotal;
                else
                    sum = rowTotal;
                
                grid[i][j] = sum;
                if(sum > k)
                    break;
                else
                    total++;
            }
        }
        return total;
    }

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> nonY(3, 0);
        vector<int> y(3, 0);
        int n = grid.size();
        int yCount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isY(j, i, n)){
                    y[grid[i][j]]++;
                    yCount++;
                }
                else
                    nonY[grid[i][j]]++;
            }
        }

        int minOperation = INT_MAX;
        int nonYCount = n*n - yCount;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == j)
                    continue;
                int operation = (yCount - y[i]) + (nonYCount - nonY[j]);
                minOperation = min(minOperation, operation);
            }
        }

        return minOperation;
    }
};


// 1 2 2 
// 1 1 0
// 0 1 0

int main(void){
    vector<vector<int> > grid;
    vector<int> t;
    t.push_back(0);
    t.push_back(0);
    t.push_back(2);
    t.push_back(1);
    t.push_back(2);
    grid.push_back(t);
    t.clear();

    t.push_back(0);
    t.push_back(0);
    t.push_back(1);
    t.push_back(0);
    t.push_back(0);
    grid.push_back(t);
    t.clear();

    t.push_back(0);
    t.push_back(1);
    t.push_back(1);
    t.push_back(2);
    t.push_back(0);
    grid.push_back(t);
    t.clear();

    t.push_back(2);
    t.push_back(0);
    t.push_back(0);
    t.push_back(1);
    t.push_back(1);
    grid.push_back(t);
    t.clear();

    t.push_back(0);
    t.push_back(1);
    t.push_back(2);
    t.push_back(1);
    t.push_back(2);
    grid.push_back(t);
    t.clear();

    Solution s;
    cout << s.minimumOperationsToWriteY(grid) << endl;
    return 0;
}