#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
    int highestSeen;
    unordered_map<int, int> seenNum;
    int RecursiveCount(int n){
        if(n == 2 || n == 3)
            return 1;
        else if(seenNum.find(n) != seenNum.end())
            return seenNum[n];
        else{
            int left = highestSeen;
            int right = n - left;
            int leftCount = RecursiveCount(left);
            seenNum.insert(pair<int, int>(left, leftCount));
            highestSeen = max(highestSeen, leftCount);
            int rightCount = RecursiveCount(right);
            seenNum.insert(pair<int, int>(right, rightCount));
            highestSeen = max(highestSeen, rightCount);
            return leftCount + rightCount;
        }
    }
public:
    int minimumRounds(vector<int>& tasks) {
        int totalRounds = 0;
        map<int, int> table;
        for(int i = 0; i < tasks.size(); i++){
            if(table.find(tasks[i]) != table.end())
                table[tasks[i]]++;
            else
                table.insert(pair<int, int>(tasks[i], 1));
        }
        map<int, int>::iterator it = table.begin();
        if(it->second > 4)
            highestSeen = 3;
        else
            highestSeen = 2;
        while(it != table.end()){
            if(it->second < 2)
                return -1;
            totalRounds += RecursiveCount(it->second);
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

    Solution s;
    cout << s.minimumRounds(tasks) << endl;
    return 0;
}