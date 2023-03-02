#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        short n = chars.size();
        short ans = 0;
        short startIndex = 0;
        short counter = 1;
        char lastChar = chars[0];

        for(int i = 1; i <= n; i++){
            if(i == n || chars[i] ^ lastChar){
                chars[startIndex++] = lastChar;
                ans++;
                if(counter > 1){
                    string temp = "";
                    while(counter){
                        temp.append(1, '0' + (counter % 10));
                        counter /= 10;
                    }
                    short m = temp.size();
                    ans += m;
                    for(int i = m - 1; i >= 0; i--){
                        chars[startIndex++] = temp[i];
                    }
                }

                if(i ^ n){
                    lastChar = chars[i];
                    counter = 1;
                }
            }
            else{
                counter++;
            }
        }

        return ans;
    }
};

int main(void){
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('1');
    chars.push_back('1');
    
    Solution s;
    int length = s.compress(chars);
    cout << "Length: " << length << endl;
    for(int i = 0; i < length; i++)
        cout << chars[i];
    cout << endl;
    return 0;
}