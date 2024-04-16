#include<iostream>
#include<vector>
using namespace std;

class Solution {
    static bool compareVect(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int> >& points) {
        int ans = 0;
        sort(points.begin(), points.end());
        int end = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > end){
                ans++;
                end = points[i][1];
            }
            else if(points[i][1] < end){
                end = points[i][1];
            }
        }
        return ans + 1;
    }
};

int main(void){
    vector<vector<int> > points;
    vector<int> point;
    point.push_back(5);
    point.push_back(16);
    points.push_back(point);

    point.clear();
    point.push_back(2);
    point.push_back(8);
    points.push_back(point);

    point.clear();
    point.push_back(1);
    point.push_back(6);
    points.push_back(point);

    point.clear();
    point.push_back(5);
    point.push_back(12);
    points.push_back(point);

    Solution s;
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}