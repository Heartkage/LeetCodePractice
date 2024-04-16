#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1;
        int firstNum = fruits[0];
        int firstStartIndex = 0;
        int firstLastIndex = 0;
        int secondNum = -1;
        int secondStartIndex = 0;
        int secondLastIndex = 0;

        int n = fruits.size();
        for(int i = 1; i < n; i++){
            if(fruits[i] == firstNum){
                firstLastIndex = i;
            }
            else if(secondNum == -1){
                secondNum = fruits[i];
                secondStartIndex = i;
                secondLastIndex = i;
            }
            else if(fruits[i] == secondNum){
                secondLastIndex = i;
            }
            else{
                if(firstStartIndex < secondStartIndex)
                    ans = max(ans, i-firstStartIndex);
                else
                    ans = max(ans, i-secondStartIndex);
                
                if(firstLastIndex < secondLastIndex){
                    secondStartIndex = firstLastIndex + 1;
                    firstNum = fruits[i];
                    firstStartIndex = firstLastIndex = i;
                }
                else{
                    firstStartIndex = secondLastIndex + 1;
                    secondNum = fruits[i];
                    secondStartIndex = secondLastIndex = i;
                }
            }
        }

        if(firstStartIndex < secondStartIndex)
            return max(ans, n-firstStartIndex);
        else
            return max(ans, n-secondStartIndex);
    }
};

int main(void){
    vector<int> fruits;
    fruits.push_back(0);
    fruits.push_back(1);
    fruits.push_back(2);
    fruits.push_back(2);

    Solution s;
    cout << s.totalFruit(fruits) << endl;
    return 0;
}