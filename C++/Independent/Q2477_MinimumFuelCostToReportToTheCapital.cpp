#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

class Solution {
    int m_seats;
    long long m_fuel;
    int dfsTravel(int cityId, vector<vector<int> > &routes, vector<bool> &checkStep){
        checkStep[cityId] = true;
        int people = 1;
        for(int i = 0; i < routes[cityId].size(); i++){
            if(checkStep[routes[cityId][i]])
                continue;
            people += dfsTravel(routes[cityId][i], routes, checkStep);
        }

        if(cityId ^ 0){
            if(people > 1){
                m_fuel += people / m_seats;
                if(people % m_seats ^ 0)
                    m_fuel++;
            }
            else
                m_fuel++;
        }

        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int> >& roads, int seats) {
        m_fuel = 0;
        m_seats = seats;
        int n = roads.size();
        vector<vector<int> > routes(n + 1, vector<int>());
        for(int i = 0; i < n; i++){
            routes[roads[i][0]].push_back(roads[i][1]);
            routes[roads[i][1]].push_back(roads[i][0]);
        }
        vector<bool> checkStep(n + 1, false);
        dfsTravel(0, routes, checkStep);
        return m_fuel;
    }
};


int main(void){
    vector<vector<int> > roads;
    vector<int> road;
    road.push_back(3);
    road.push_back(1);
    roads.push_back(road);

    road.clear();
    road.push_back(3);
    road.push_back(2);
    roads.push_back(road);
    
    road.clear();
    road.push_back(1);
    road.push_back(0);
    roads.push_back(road);

    road.clear();
    road.push_back(0);
    road.push_back(4);
    roads.push_back(road);

    road.clear();
    road.push_back(0);
    road.push_back(5);
    roads.push_back(road);

    road.clear();
    road.push_back(4);
    road.push_back(6);
    roads.push_back(road);

    road.clear();
    road.push_back(1);
    road.push_back(7);
    roads.push_back(road);

    Solution s;
    cout << s.minimumFuelCost(roads, 1) << endl;
    return 0;
}