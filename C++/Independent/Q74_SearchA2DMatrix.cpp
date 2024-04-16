#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int low = 0;
        int top = matrix.size();
        while(low < top - 1){
            int index = (low + top) / 2;
            if(matrix[index][0] > target)
                top = index;
            else{
                low = index;
                if(low >= top){
                    low = top - 1;
                    break;
                }   
            }
        }
        int left = 0;
        int right = matrix[low].size();
        while(left < right){
            int index = (left + right) / 2;
            if(matrix[low][index] == target)
                return true;
            else if(matrix[low][index] > target)
                right = index;
            else{
                left = index + 1;
                if(left >= right)
                    break;
            }
        }
        return false;
    }
};

int main(void){
    vector<vector<int> > input;
    vector<int> row;
    for(int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j+=2){
            row.push_back(j + i*10);
        }
        input.push_back(row);
        row.clear();
    }

    Solution s;
    for(int i = 0; i <= 100; i++)
        cout << "i=" << i << ": " << s.searchMatrix(input, i) << endl;
    // cout << "i=33" << ": " << s.searchMatrix(input, 33) << endl;
    return 0;
}