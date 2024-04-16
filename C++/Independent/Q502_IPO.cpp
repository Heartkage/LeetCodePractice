#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int> > revenue(n);
        // O(n)
        for(int i = 0; i < n; i++){
            revenue[i].first = capital[i];
            revenue[i].second = profits[i];
        }

        // O(n Log(n))
        sort(revenue.begin(), revenue.end());

        priority_queue<int> pq;
        int index = 0;
        // O(n)
        while(k--){
            for(;index < n; index++){
                // O(log(n))
                if(revenue[index].first <= w)
                    pq.push(revenue[index].second);
                else
                    break;
            }
            
            if(pq.empty())
                break;
            // O(log(n))
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

int main(void){
    vector<int> profits;
    profits.push_back(1);
    profits.push_back(2);
    profits.push_back(3);

    vector<int> capital;
    capital.push_back(0);
    capital.push_back(1);
    capital.push_back(1);

    int k = 2;
    int w = 0;
    Solution s;
    cout << s.findMaximizedCapital(k, w, profits, capital) << endl;

    return 0;
}