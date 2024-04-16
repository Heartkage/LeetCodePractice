#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> counter(n + 1, 0);
        
        for(int i = 0; i < n; i++){
            if(arr[i] > n)
                counter[n]++;
            else
                counter[arr[i]]++;
        }

        int lastEmptyIndex = 0;
        for(int i = 1; i <= n; i++){
            if(counter[i] != 0){
                int stepAmount = counter[i];
                int needAmount = i - lastEmptyIndex;
                if(stepAmount > needAmount)
                    lastEmptyIndex = i;
                else
                    lastEmptyIndex = lastEmptyIndex + stepAmount;
            }
        }
        return lastEmptyIndex;
    }
};

int main(void){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(1);
    Solution s;
    cout << s.maximumElementAfterDecrementingAndRearranging(arr) << endl;
    return 0;
}