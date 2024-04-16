#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int index = 0;
        int penalty = 0;
        int yPenalty = 0;
        for(int i = 0; i < customers.length(); i++){
            if(customers[i] == 'Y'){
                yPenalty++;
                // cout << "i: " << i << ", P: " << penalty << ", yPenalty: " << yPenalty << endl;
                if(penalty < yPenalty){
                    index = i + 1;
                    penalty = 0;
                    yPenalty = 0;
                    // cout << "New Index: " << index << endl;
                }
            }
            else{
                penalty++;
                // cout << "i: "<< i << ", P: " << penalty << endl;
            }
        }
        return index;
    }
};

int main(void){
    Solution s;
    string inputString = "NYNNNYYNYYY";
    int startIndex = 1;
    for(int i = startIndex; i <= inputString.length(); i++)
        cout << s.bestClosingTime(inputString.substr(0, i)) << endl << endl;
    
    return 0;
}