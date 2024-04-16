#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = pow(10, 9) + 7;
        long ans = 1;
        
        int n = corridor.length();
        int index = 0;
        while(corridor[index] != 'S' && index < n) index++;

        int seatCounter = 0;
        int plantCounter = 0;
        for(int i = index; i < n; i++){
            if(corridor[i] == 'S'){
                if(seatCounter == 2){
                    if(plantCounter > 0){
                        ans *= (plantCounter+1);
                        ans %= mod;
                    }
                    seatCounter = 1;
                }
                else
                    seatCounter++;
                plantCounter = 0;
            }
            else if(seatCounter == 2)
                plantCounter++;
        }

        if(seatCounter != 2)
            return 0;
        else
            return ans;
    }
};

int main(void){
    Solution s;
    cout << s.numberOfWays("SSPPSSPPSSPP") << endl;
    return 0;
}