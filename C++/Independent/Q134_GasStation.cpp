#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int currentRoute = 0;
        int count = 0;
        for(int i = 0; i < n*2; i++){
            int index = i >= n ? i - n : i;
            currentRoute += gas[index] - cost[index];
            count++;

            if(currentRoute < 0){
                currentRoute = 0;
                count = 0;
            }
            if(count == n)
                return i - (count-1);
        }
        return -1;
    }
};

int main(void){

    vector<int>gas;
    gas.push_back(5);
    gas.push_back(8);
    gas.push_back(2);
    gas.push_back(8);

    vector<int> costs;
    costs.push_back(6);
    costs.push_back(5);
    costs.push_back(6);
    costs.push_back(6);
    Solution s;
    cout << s.canCompleteCircuit(gas, costs) << endl;
    return 0;
}