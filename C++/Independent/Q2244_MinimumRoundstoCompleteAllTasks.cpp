#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int totalRounds = 0;
        unordered_map<int, int> table;
        for(int i = 0; i < tasks.size(); i++){
            if(table.find(tasks[i]) != table.end())
                table[tasks[i]]++;
            else
                table.insert(pair<int, int>(tasks[i], 1));
        }
        unordered_map<int, int>::iterator it = table.begin();
        while(it != table.end()){
            int count = it->second;
            if(count < 2)
                return -1;
            else
                totalRounds += ceil(count / 3.0);
            it++;
        }
        return totalRounds;
    }
};

int main(void){
    vector<int> tasks;
    tasks.push_back(2);
    tasks.push_back(2);
    tasks.push_back(3);
    tasks.push_back(3);
    tasks.push_back(2);
    tasks.push_back(4);
    tasks.push_back(4);

    Solution s;
    cout << s.minimumRounds(tasks) << endl;
    return 0;
}