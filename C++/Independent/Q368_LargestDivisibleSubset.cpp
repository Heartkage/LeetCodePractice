#include<iostream>
#include<vector>
using namespace std;

//    1 2 3 4 5 6 7 8 12
//  1 1 0 0 0 0 0 0 0 0
//  2 1 2 0 0 0 0 0 0 0
//  3 1 2 2 
//  4 1 2 2 3
//  5 1 2 2 3 2
//  6 1 2 2 3 2 3
//  7 1 2 2 3 2 3 2
//  8 1 2 2 3 2 3 2 4
// 12 1 2 2 3 2 3 2 4 4


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> route(n, -1);

        int max = 0;
        int maxIndex = 0;
        for(int i = 0; i < n; i++){
            int m = 1;
            int mIndex = -1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(m < dp[j] + 1){
                        m = dp[j] + 1;
                        mIndex = j;
                    }
                }
            }
            dp[i] = m;
            route[i] = mIndex;
            if(dp[i] > max){
                max = dp[i];
                maxIndex = i;
            }
        }
        vector<int> output(max);
        int index = 0;
        while(maxIndex >= 0){
            output[index++] = nums[maxIndex];
            maxIndex = route[maxIndex];
        }
        return output;
    }
};

int main(void){
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    input.push_back(5);
    input.push_back(6);
    input.push_back(7);
    input.push_back(8);
    input.push_back(36);
    input.push_back(72);

    Solution s;
    auto output = s.largestDivisibleSubset(input);

    cout << endl;
    for(auto o : output)
        cout << o << endl;

    return 0;
}