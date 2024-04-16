#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
    bool StringNumberLesserThan256(const string &s){
        int n = s.length();
        if(n < 3)
            return true;
        else if(n > 3)
            return false;
        else{
            if(s[0] > '2')
                return false;
            else if(s[0] < '2')
                return true;
            else if(s[1] > '5')
                return false;
            else if(s[1] < '5')
                return true;
            else if(s[2] > '5')
                return false;
            else
                return true;
        }
    }
    void RecursivePlaceDots(int depth, int index, string &s, string &currentAns, vector<string> &ans){
        int n = s.size();
        if(depth == 4){
            if(index == n)
                return;
            else if(n - index > 3)
                return;
            else if(s[index] == '0' && (n - 1) > index)
                return;
            else if(StringNumberLesserThan256(s.substr(index)) == false)
                return;
            else
            {
                currentAns.insert(currentAns.end(), s.begin()+index, s.end());
                ans.push_back(currentAns);
                currentAns.erase(currentAns.begin() + index + 3, currentAns.end());
            }
        }
        else{
            for(int i = index; i < n && i-index < 3; i++){
                if(i > index && s[index] == '0')
                    continue;
                else if(i == index+2 && !StringNumberLesserThan256(s.substr(index, i-index+1))){
                    continue;
                }

                currentAns.insert(currentAns.end(), s.begin()+index, s.begin()+i+1);
                currentAns.push_back('.');
                RecursivePlaceDots(depth+1, i+1, s, currentAns, ans);
                currentAns.pop_back();
                currentAns.erase(currentAns.begin() + index + depth - 1, currentAns.end());
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string currentAns;
        RecursivePlaceDots(1, 0, s, currentAns, ans);
        return ans;
    }
};

int main(void){
    Solution s;
    vector<string> output = s.restoreIpAddresses("25525511135");
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
    return 0;
}