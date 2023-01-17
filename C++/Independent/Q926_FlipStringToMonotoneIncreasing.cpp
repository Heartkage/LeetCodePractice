#include<iostream>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        int last1Count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1')
                last1Count++;
            else{
                ans++;
                ans = min(ans, last1Count);
            }
        }
        return ans;
    }
};

int main(void){
    Solution s;
    cout << s.minFlipsMonoIncr("111010011") << endl;

    return 0;
}