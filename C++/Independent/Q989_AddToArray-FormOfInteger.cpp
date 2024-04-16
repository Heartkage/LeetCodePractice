#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        bool carry = false;
        int index = num.size();
        while(k){
            if(--index < 0)
                num.insert(num.begin(), 0);

            int i = max(0, index);
            num[i] += k % 10;
            k /= 10;
            if(carry){
                num[i]++;
                if(num[i] > 9)
                    num[i] -= 10;
                else
                    carry = false;
            }
            else{
                if(num[i] > 9){
                    num[i] -= 10;
                    carry = true;
                }
            }
        }
        while(carry){
            if(--index < 0)
                num.insert(num.begin(), 0);

            int i = max(0, index);
            if(num[i] > 8)
                num[i] = 0;
            else{
                num[i]++;
                carry = false;
            }
        }
        return num;
    }
};

int main(void){
    vector<int> num;
    num.push_back(1);

    Solution s;
    num = s.addToArrayForm(num, 3456);

    for(int i = 0; i < num.size(); i++){
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}