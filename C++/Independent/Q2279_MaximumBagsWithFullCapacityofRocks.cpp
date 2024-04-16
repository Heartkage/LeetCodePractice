#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int totalBags = 0;
        for(int i = 0; i < capacity.size(); i++)
            rocks[i] = capacity[i] - rocks[i];

        sort(rocks.begin(), rocks.end());

        for(int i = 0; i < rocks.size(); i++){
            if(additionalRocks < rocks[i])
                break;
            additionalRocks -= rocks[i];
            totalBags++;
        }
        return totalBags;
    }
};

int main(void){

    vector<int> capacity;
    capacity.push_back(2);
    capacity.push_back(3);
    capacity.push_back(4);
    capacity.push_back(5);
    vector<int> rocks;
    rocks.push_back(1);
    rocks.push_back(2);
    rocks.push_back(4);
    rocks.push_back(4);
    Solution s;
    
    cout << "Answer: " << s.maximumBags(capacity, rocks, 2) << endl; 

    return 0;
}