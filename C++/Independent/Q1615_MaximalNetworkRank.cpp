#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void printTable(vector<vector<int> > &table){
        int n = table.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int> >& roads) {
        vector<vector<int> > table(n, vector<int>(n, 0));
        
        int totalRoads = roads.size();
        for(int i = 0; i < totalRoads; i++){
            int city1 = min(roads[i][0], roads[i][1]);
            int city2 = max(roads[i][0], roads[i][1]);
            table[city1][city2] = 1;
        }
        // printTable(table);

        for(int i = 0; i < totalRoads; i++){
            int city1 = min(roads[i][0], roads[i][1]);
            int city2 = max(roads[i][0], roads[i][1]);
            // cout << "(" << city1 << "," << city2 << ")" << endl;
            for(int j = 0; j < n; j++){
                if(j != city2)
                    table[city1][j]++;
                if(j != city2)
                    table[j][city1]++;
            }
            for(int j = 0; j < n; j++){
                if(j != city1)
                    table[city2][j]++;
                if(j != city1)
                    table[j][city2]++;
            }
            // printTable(table);
        }

        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(table[i][j] > max)
                    max = table[i][j];
            }
        }
        return max;
    }
};

int main(void){

    vector<vector<int> > roads;
    vector<int> road;
    road.push_back(0);
    road.push_back(1);
    roads.push_back(road);

    road.clear();
    road.push_back(1);
    road.push_back(2);
    roads.push_back(road);

    road.clear();
    road.push_back(2);
    road.push_back(3);
    roads.push_back(road);

    road.clear();
    road.push_back(2);
    road.push_back(4);
    roads.push_back(road);

    road.clear();
    road.push_back(5);
    road.push_back(6);
    roads.push_back(road);

    road.clear();
    road.push_back(5);
    road.push_back(7);
    roads.push_back(road);

    Solution s;
    cout << s.maximalNetworkRank(8, roads) << endl;
    return 0;
}