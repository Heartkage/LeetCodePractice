#include<iostream>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();

        char a1 = '\0', a2 = '\0';
        bool check = false;
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                if (check) {
                    return false;
                } else if (a1 == '\0') {
                    a1 = s1[i];
                    a2 = s2[i];
                    // cout << "a1: " << a1 << ", a2: " << a2 << endl;
                } else {
                    if (a1 != s2[i] || a2 != s1[i]){
                        return false;
                    } else {
                        check = true;
                    }
                }
            }
        }

        return a1 == '\0' || check;
    }
};

int main(void) {

    Solution s;
    bool result = s.areAlmostEqual("kang", "gank");
    if (result) {
        cout << "ans: true" <<  endl; 
    } else {
        cout << "ans: false" << endl; 
    }

    return 0;
}