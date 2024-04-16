#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>

using namespace std;

struct Compare{
    bool operator()(const vector<int> &a, const vector<int> &b){
        if(a[1] != b[1])
            return a[1] > b[1];
        else
            return a[2] > b[2];
    }
};

class Solution {
    static bool CompareVec(const vector<int> &a, const vector<int> &b){
        if(a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    }
public:
    vector<int> getOrder(vector<vector<int> >& tasks) {
        vector<int> answer;
        for(int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end(), CompareVec);

        int taskEndIndex = tasks.size();
        int endIndex = 0;
        long cpuTime = 0;
        priority_queue<vector<int>, vector<vector<int> >, Compare> pq;
        do{
            for(int i = endIndex; i < tasks.size(); i++){
                if(tasks[i][0] <= cpuTime){
                    pq.push(tasks[i]);
                    endIndex++;
                }
                else
                    break;
            }

            if(pq.empty()){
                pq.push(tasks[endIndex]);
                cpuTime = tasks[endIndex][0];
                endIndex++;
            }

            if(!pq.empty()){
                answer.push_back(pq.top()[2]);
                cpuTime += *(pq.top()[1]);
                pq.pop();
            }

        }while(!pq.empty() || (endIndex < taskEndIndex));
        return answer;
    }   
};

int main(void){
    vector<vector<int> > tasks;
    vector<int> task1;

    task1.push_back(16);
    task1.push_back(9);
    tasks.push_back(task1);


    task1.clear();
    task1.push_back(21);
    task1.push_back(10);
    tasks.push_back(task1);

    task1.clear();
    task1.push_back(49);
    task1.push_back(24);
    tasks.push_back(task1);

    task1.clear();
    task1.push_back(2);
    task1.push_back(15);
    tasks.push_back(task1);

    task1.clear();
    task1.push_back(18);
    task1.push_back(18);
    tasks.push_back(task1);

    task1.clear();
    task1.push_back(12);
    task1.push_back(24);
    tasks.push_back(task1);

    Solution s;
    vector<int> answer = s.getOrder(tasks);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}