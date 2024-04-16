#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
using namespace std;



class Solution {
    
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for(int i = 0; i < apple.size(); i++)
            total += apple[i];
        
        sort(capacity.begin(), capacity.end(), [](int a, int b){
            return a > b;
        });
        int m = capacity.size();
        for(int i = 0; i < m; i++){
            if(total <= 0)
                return i;
            total -= capacity[i];
        }

        return m;
    }

    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < happiness.size(); i++)
            pq.push(happiness[i]);

        int selected = 0;
        long long ans = 0;
        while(selected < k){
            int next = pq.top();
            // cout << next << endl;
            ans += max(0, pq.top()-selected);
            pq.pop();
            selected++;
        }
        return ans;
    }

    vector<string> shortestSubstrings(vector<string>& arr) {
        set<string> table;
        for(int i = 0; i < arr.size(); i++){
            int length = arr[i].length();
            string ans = "";
            for(int j = 1; j <= length; j++){
                for(int k = 0; k+j <= length; k++){
                    string subStr = arr[i].substr(k, j);
                    cout << "subStr:" << subStr << endl;
                    if(table.count(subStr) > 0){
                        cout << "found in table" << endl;
                        continue;
                    }
                    
                    bool found = false;
                    for(int l = i+1; l < arr.size(); l++){
                        if(arr[l].find(subStr) != string::npos){
                            cout << "found subStr in: " << arr[l] << endl;
                            table.insert(subStr);
                            found = true;
                            break;
                        }
                    }

                    if(found == false){
                        if(ans.compare("") == 0)
                            ans = subStr;
                        else if(subStr.length() <= ans.length()){
                            if(subStr.compare(ans) < 0)
                                ans = subStr;
                        }
                    }
                }
            }
            arr[i] = ans;
        }
        
        return arr;
    }
};

int main(void){
    vector<string> arr;
    arr.push_back("nrvnc");
    arr.push_back("nr");
    Solution s;
    arr = s.shortestSubstrings(arr);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    return 0;
}