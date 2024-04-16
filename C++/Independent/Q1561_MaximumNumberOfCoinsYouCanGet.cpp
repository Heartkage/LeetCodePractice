#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int takeChance = piles.size() / 3;
        int index = piles.size()-2;
        int ans = 0;
        while(takeChance--){
            ans += piles[index];
            index -= 2;
        }
        return ans;
    }
};

int main(void){
    vector<int> piles;
    for(int i = 1; i <= 9; i++)
        piles.push_back(i);
    Solution s;
    cout << s.maxCoins(piles) << endl;
    return 0;
}