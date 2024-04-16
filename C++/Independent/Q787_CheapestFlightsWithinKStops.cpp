#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    // void dfs(vector<vector<pair<int, int> > > &graph, int currentStop, int stopsRemaining, int price, int *endStop, int *ans){
    //     if(currentStop == (*endStop))
    //         (*ans) = min((*ans), price);
    //     else if(stopsRemaining < 1)
    //         return;
    //     else{
    //         for(int i = 0; i < graph[currentStop].size(); i++){
    //             price += graph[currentStop][i].second;
    //             dfs(graph, graph[currentStop][i].first, stopsRemaining - 1, price, endStop, ans);
    //             price -= graph[currentStop][i].second;
    //         }
    //     }
    // }
public:
    int findCheapestPrice(int n, vector<vector<int> >& flights, int src, int dst, int k) {
        vector<int> routeCost(n, INT_MAX);
        vector<vector<pair<int, int> > > graph(n, vector<pair<int, int> >());
        for(int i = 0; i < flights.size(); i++){
            graph[flights[i][0]].push_back(pair<int, int>(flights[i][1], flights[i][2]));
        }

        queue<int> bfsQueue;
        queue<pair<int, int> > updateQueue;
        bfsQueue.push(src);
        routeCost[src] = 0;
        ++k;
        while(k--){
            int thisRoundPopCount = bfsQueue.size();
            while(thisRoundPopCount--){
                int currentCity = bfsQueue.front(); bfsQueue.pop();
                for(int i = 0; i < graph[currentCity].size(); i++){
                    int nextCity = graph[currentCity][i].first;

                    if(routeCost[currentCity] + graph[currentCity][i].second < routeCost[nextCity]){
                        updateQueue.push(pair<int, int>(nextCity, routeCost[currentCity] + graph[currentCity][i].second));
                        bfsQueue.push(nextCity);
                    }
                }
            }

            while(!updateQueue.empty()){
                pair<int, int> p = updateQueue.front();
                routeCost[p.first] = min(routeCost[p.first], p.second);
                updateQueue.pop();
            }
        }
        return routeCost[dst] != INT_MAX ? routeCost[dst] : -1;
    }
};

int main(void){
    vector<vector<int> > flights;
    vector<int> flight;
    flight.push_back(0);
    flight.push_back(1);
    flight.push_back(5);
    flights.push_back(flight);

    flight.clear();
    flight.push_back(1);
    flight.push_back(2);
    flight.push_back(5);
    flights.push_back(flight);

    flight.clear();
    flight.push_back(0);
    flight.push_back(3);
    flight.push_back(2);
    flights.push_back(flight);

    flight.clear();
    flight.push_back(3);
    flight.push_back(1);
    flight.push_back(2);
    flights.push_back(flight);

    flight.clear();
    flight.push_back(1);
    flight.push_back(4);
    flight.push_back(1);
    flights.push_back(flight);

    flight.clear();
    flight.push_back(4);
    flight.push_back(2);
    flight.push_back(1);
    flights.push_back(flight);


    Solution s;
    cout << s.findCheapestPrice(5, flights, 0 , 2, 2) << endl;
    return 0;
}