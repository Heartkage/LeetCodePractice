#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int> >& points) {
        int n = points.size();
        int ans = 2;
        if(n < ans)
            return n;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int currentPoint = 2;
                for(int k = j + 1; k < n; k++){
                    if((points[j][1] - points[i][1]) * (points[k][0] - points[i][0]) == (points[k][1] - points[i][1]) * (points[j][0] - points[i][0])){
                        currentPoint++;
                        ans = max(currentPoint, ans);
                    }
                }
            }
        }
        return ans;
    }
};

int main(void){
    vector<vector<int> > input;
    vector<int> point;

    point.push_back(1);
    point.push_back(1);
    input.push_back(point);

    point.clear();
    point.push_back(3);
    point.push_back(2);
    input.push_back(point);

    point.clear();
    point.push_back(5);
    point.push_back(3);
    input.push_back(point);

    point.clear();
    point.push_back(4);
    point.push_back(1);
    input.push_back(point);

    point.clear();
    point.push_back(2);
    point.push_back(3);
    input.push_back(point);

    point.clear();
    point.push_back(1);
    point.push_back(4);
    input.push_back(point);

    Solution s;
    cout << s.maxPoints(input) << endl;
    return 0;
}