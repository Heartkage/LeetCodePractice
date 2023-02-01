#include<iostream>
using namespace std;

class Solution {
    bool isgcdOfString(const string &str, const string &sub){
        int n = str.size();
        int m = sub.size();
        if(n % m == 0){
            for(int i = 0; i < n; i+=m){
                if(str.substr(i, m).compare(sub))
                    return false;
            }
            return true;
        }
        else
            return false;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int str1n = str1.size();
        int str2n = str2.size();
        int n = min(str1n, str2n) + 1;
        while(--n){
            if((str1n % n == 0) && (str2n % n == 0)){
                string sub = str1.substr(0, n);
                if(isgcdOfString(str1, sub) == false)
                    continue;
                else if(isgcdOfString(str2, sub) == false)
                    continue;
                else
                    return sub;
            }
        }
        return "";
    }
};

int main(void){
    Solution s;
    cout << s.gcdOfStrings("ABABAB", "ABAB") << endl;
    return 0;
}