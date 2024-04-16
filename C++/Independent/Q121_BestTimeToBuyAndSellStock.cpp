#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        short min = 10001;
        short max = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min)
                min = prices[i];
            else if(prices[i]-min > max)
                max = prices[i]-min;
        }
        return max;
    }
};

int main(void){
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}