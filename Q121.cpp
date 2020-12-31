#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int bestAnswer = 0;
        int currentLowestPurchase = 2147483647;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] <= currentLowestPurchase)
                currentLowestPurchase = prices[i];
            else if(prices[i] - currentLowestPurchase > bestAnswer)
                bestAnswer = prices[i] - currentLowestPurchase;         
        }
        return bestAnswer;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution solution;

    cout << solution.maxProfit(prices) << endl;

    return 0;
}