#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int total = 0;
        sort(costs.begin(), costs.end());
        for(int i = 0; i < costs.size(); i++){
            coins -= costs[i];
            if(coins < 0)
                break;
            total++;
        }
        return total;
    }
};

int main(void){
    vector<int> costs;
    costs.push_back(1);
    costs.push_back(3);
    costs.push_back(2);
    costs.push_back(4);
    costs.push_back(1);
    Solution s;
    cout << s.maxIceCream(costs, 7) << endl;
    return 0;
}