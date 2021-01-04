#include<iostream>
#include<vector>
using namespace std;

class Solution121 {
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

class Solution122 {
public:
    int maxProfit(vector<int>& prices) 
    {
        int bestAnswer = 0;
        if(prices.size() > 0)
        {
            int lowest = prices[0];
            int highest = prices[0];
            for(int i = 1; i < prices.size(); i++)
            {
                if(prices[i] < highest)
                {
                    bestAnswer += highest - lowest;
                    lowest = highest = prices[i];
                }
                else
                {
                    highest = prices[i];
                }
            }
            bestAnswer += highest - lowest;
        }
        return bestAnswer;
    }
};

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution121 solution;

    cout << solution.maxProfit(prices) << endl;

    return 0;
}