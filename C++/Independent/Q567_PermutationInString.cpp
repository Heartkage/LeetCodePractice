#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> character(26, -1);
        int n = s1.size();
        for(int i = 0; i < n; i++){
            if(character[s1[i]-'a'] < 0)
                character[s1[i]-'a'] = 0;
            character[s1[i]-'a']++;
        }
        
        int counter = 0;
        int startIndex = 0;
        for(int i = 0; i < s2.size(); i++){
            if(character[s2[i]-'a'] > 0){
                if(counter == 0)
                    startIndex = i;
                character[s2[i]-'a']--;
                counter++;
            }
            else if(character[s2[i]-'a'] == 0){
                int total = startIndex+counter;
                for(int j = startIndex; j < total; j++){
                    if(s2[j] == s2[i]){
                        startIndex = j + 1;
                        break;
                    }
                    else{
                        character[s2[j]-'a']++;
                        counter--;
                    }
                }
            }
            else{
                for(int j = startIndex; j < startIndex+counter; j++)
                    character[s2[j]-'a']++;
                counter = 0;
            }

            if(counter == n)
                return true;
        }
        return false;
    }
};

int main(void){
    Solution s;
    cout << s.checkInclusion("ky", "ainwkckifykxlribaypk") << endl;
    return 0;
}