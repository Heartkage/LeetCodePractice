#include<iostream>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int numsBetween = high-low+1;
        if(numsBetween & 1){
            if(low & 1)
                return (numsBetween-1) / 2 + 1;
            else
                return numsBetween / 2;
        }
        else
            return numsBetween / 2;
    }
};

int main(void){
    Solution s;
    cout << s.countOdds(1, 3) << endl;
    return 0;
}