#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        short n = a.size();
        short m = b.size();
        if(n < m){
            swap(a, b);
            swap(n, m);
        }

        bool hasCarry = false;
        for(short i = 0; i < n; i++){
            if(i < m){
                if(a[i]&1 && b[i]&1){
                    if(!hasCarry){
                        a[i] = '0';
                        hasCarry = true;
                    }
                }
                else{
                    if(hasCarry && (a[i]&1 || b[i]&1))
                        a[i] = '0';
                    else{
                        if(hasCarry || b[i]&1)
                            a[i] = '1';
                        hasCarry = false;
                    } 
                }
            }
            else{
                if(hasCarry){
                    if(a[i]&1)
                        a[i] = '0';
                    else{
                        a[i] = '1';
                        hasCarry = false;
                    }
                }
            }
        }
        if(hasCarry)
            a.push_back('1');
        reverse(a.begin(), a.end());
        return a;
    }
};

int main(void){
    Solution s;
    cout << s.addBinary("11000010", "11") << endl;
    return 0;
}