#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(n <= numRows)
            return s;

        string ans = s;
        int counter = 0;
        for(int i = 0; i < numRows; i++){
            for(int j = i; j < n;){
                ans[counter++] = s[j];
                if(i > 0 & i < (numRows-1)){
                    int iDifference = (numRows-1) - i;
                    int secondIndex = j + (iDifference*2);
                    if(secondIndex < n)
                        ans[counter++] = s[secondIndex];
                }
                j += max(1, (numRows-1)*2);
            }
        }
        return ans;
    }
};

int main(void){
    Solution s;
    cout << s.convert("PAYPALISHIRING", 1) << endl;
    return 0;
}