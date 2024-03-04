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
        cout << n << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isY(j, i, n)){
                    y[grid[i][j]]++;
                    cout << grid[i][j];
                }
                else{
                    nonY[grid[i][j]]++;
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;

        int chosenNonYIndex = 0;
        for(int i = 0; i < 3; i++){
            if(nonY[i] > nonY[chosenNonYIndex])
                chosenNonYIndex = i;
        }
        int needNonYOperation = 0;
        int completeNonY = 0;
        cout << "Non-Y:" << endl;
        for(int i = 0; i < 3; i++){
            if(i == chosenNonYIndex)
                completeNonY = nonY[i];
            else
                needNonYOperation += nonY[i];
            cout << "i=" << i << ", " << nonY[i] << endl;
        }
        cout << endl;

        cout << "Y:" << endl;
        int chosenYIndex = 0;
        for(int i = 0; i < 3; i++){
            if(y[i] > y[chosenYIndex])
                chosenYIndex = i;
        }
        int needYOperation = 0;
        int completeY = 0;
        for(int i = 0; i < 3; i++){
            if(i == chosenYIndex)
                completeY = y[i];
            else
                needYOperation += y[i];
            cout << "i=" << i << ", " << y[i] << endl;
        }
        cout << endl;
        
        if(chosenNonYIndex != chosenYIndex){
            return needNonYOperation + needYOperation;
        }
        else{
            if(completeNonY > completeY){
                chosenYIndex = chosenNonYIndex == 0 ? 1 : 0;
                for(int i = 0; i < 3; i++){
                    if(i == chosenNonYIndex)
                        continue;
                    
                    if(y[i] > y[chosenYIndex])
                        chosenYIndex = i;
                }
                needYOperation = 0;
                for(int i = 0; i < 3; i++){
                    if(i == chosenYIndex)
                        completeY = y[i];
                    else
                        needYOperation += y[i];
                }
            }
            else{
                chosenNonYIndex = chosenYIndex == 0 ? 1 : 0;
                for(int i = 0; i < 3; i++){
                    if(i == chosenYIndex)
                        continue;

                    if(nonY[i] > nonY[chosenNonYIndex])
                        chosenNonYIndex = i;
                }
                needNonYOperation = 0;
                for(int i = 0; i < 3; i++){
                    if(i == chosenNonYIndex)
                        completeNonY = nonY[i];
                    else
                        needNonYOperation += nonY[i];
                }
            }
            return needNonYOperation + needYOperation;
        }

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