#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int answer = 0;
        priority_queue<int> pq;
        for(int i = 0; i < piles.size(); i++)
            pq.push(piles[i]);
        
        while(k--){
            pq.push((int)ceil(pq.top() / 2.0));
            pq.pop();
        }

        while(pq.size()){
            answer += pq.top();
            pq.pop();
        }

        return answer;
    }
};

int main(void){

    vector<int> piles;
    piles.push_back(4);
    piles.push_back(3);
    piles.push_back(7);
    piles.push_back(6);
    Solution s;
    cout << s.minStoneSum(piles, 3) << endl;
    return 0;
}