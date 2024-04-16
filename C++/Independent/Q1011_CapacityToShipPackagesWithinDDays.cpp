#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total = 0;
        int maxWeight = -1;
        int n = weights.size();
        for(int i = 0; i < n; i++){
            total += weights[i];
            maxWeight = max(maxWeight, weights[i]);
        }

        while(maxWeight < total){
            int midWeight = maxWeight + (total - maxWeight) / 2;
            int neededDays = 1;
            int currentWeight = 0;
            for(int i = 0; i < n; i++){
                if(currentWeight + weights[i] > midWeight){
                    currentWeight = 0;
                    neededDays++;
                }
                currentWeight += weights[i];
            }

            if(neededDays > days)
                maxWeight = midWeight + 1;
            else
                total = midWeight;
        }

        return maxWeight;
    }
};

int main(void){
    vector<int> days;
    days.push_back(1);
    days.push_back(2);
    days.push_back(3);
    days.push_back(4);
    days.push_back(5);
    days.push_back(6);
    days.push_back(7);
    days.push_back(8);
    days.push_back(9);
    days.push_back(10);

    Solution s;
    cout << s.shipWithinDays(days, 5) << endl;

    return 0;
}