#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        int startIndex;
        int lastBack = -1;
        bool foundStart = false;
        int lastIndex = intervals.size()-1;
        if(intervals.size() > 0){
            for(int i = 0; i < intervals.size(); i++){
                if(foundStart == false){
                    // [..., 1] [2, ...] [4, ...]
                    if(newInterval[0] > lastBack && newInterval[0] < intervals[i][0]){
                        // [..., 1] [2, 3] [4, ...]
                        if(newInterval[1] < intervals[i][0]){
                            intervals.insert(intervals.begin() + i, newInterval);
                            break;
                        }
                        else{
                            startIndex = i;
                            intervals[i][0] = newInterval[0];
                            foundStart = true;

                            if(newInterval[1] > intervals[i][1] && (i == lastIndex))
                                intervals[i][1] = newInterval[1];
                        }
                    }
                    else if(newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]){
                        startIndex = i;
                        foundStart = true;
                        if((newInterval[1] > intervals[i][1]) && (i == lastIndex))
                            intervals[i][1] = newInterval[1];
                    }
                    else if(newInterval[0] > intervals[i][1] && (i == lastIndex)){
                        intervals.insert(intervals.begin() + i + 1, newInterval);
                        break;
                    }
                }
                else{
                    if(newInterval[1] > lastBack && newInterval[1] < intervals[i][0]){
                        intervals[startIndex][1] = newInterval[1];
                        if((startIndex + 1) <= (i - 1))
                            intervals.erase(intervals.begin()+startIndex+1, intervals.begin() + i);
                        break;
                    }
                    else if(newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                        intervals[startIndex][1] = intervals[i][1];
                        if((startIndex + 1) <= i)
                            intervals.erase(intervals.begin()+startIndex+1, intervals.begin() + i + 1);
                        break;
                    }
                    else if(newInterval[1] > intervals[i][1] && (i == lastIndex)){
                        intervals[startIndex][1] = newInterval[1];
                        if((startIndex + 1) <= i)
                            intervals.erase(intervals.begin()+startIndex+1, intervals.begin() + i + 1);
                        break;
                    }
                }

                lastBack = intervals[i][1];
            }
        }
        else{
            intervals.push_back(newInterval);
        }
        return intervals;
    }
};

int main(void){
    vector<vector<int> > intervals;
    vector<int> interval;

    interval.push_back(0);
    interval.push_back(0);
    intervals.push_back(interval);

    interval.clear();
    interval.push_back(2);
    interval.push_back(4);
    intervals.push_back(interval);

    interval.clear();
    interval.push_back(9);
    interval.push_back(9);
    intervals.push_back(interval);

    vector<int> newInterval;
    newInterval.push_back(0);
    newInterval.push_back(7);

    Solution s;
    vector<vector<int> > output = s.insert(intervals, newInterval);

    for(int i = 0; i < output.size(); i++){
        for(int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}