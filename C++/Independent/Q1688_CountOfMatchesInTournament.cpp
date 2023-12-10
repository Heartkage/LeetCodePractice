#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        while(n > 1){
            bool hasExtra = (n & 1);
            n >>= 1;
            matches += n;
            if(hasExtra)
                n++;
        }
        return matches;
    }
};

int main(void){
    Solution s;
    cout << s.numberOfMatches(7) << endl;
    return 0;
}