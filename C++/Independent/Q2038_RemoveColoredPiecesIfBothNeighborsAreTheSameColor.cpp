#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int aCount = 0, bCount = 0;
        int n = colors.length();
        int counter = 0;
        for(int i = 0; i < n; i++){
            if(colors[i] == 'A'){
                counter = 1;
                while(++i < n && colors[i] == 'A')
                    counter++;
                aCount += max(counter - 2, 0);
                --i;
            }
            else{
                counter = 1;
                while(++i < n && colors[i] == 'B')
                    counter++;
                bCount += max(counter - 2, 0);
                --i;
            }
        }
        return aCount > bCount;
    }
};

int main(void){
    Solution s;
    cout << s.winnerOfGame("BBBAAAABB") << endl;
    return 0;
}