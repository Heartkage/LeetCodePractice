#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<math.h>
using namespace std;



class Solution {
    
public:
    bool isValid(string word) {
        if(word.length() < 3)
            return false;
        
        bool hasVowel = false;
        bool hasConsonant = false;

        for(int i = 0; i < word.length(); i++){
            if((word[i] >= '0' && word[i] <= '9') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z')){
                if(word[i] >= '0' && word[i] <= '9') {
                    continue;
                }
                else if(word[i] == 'a' || word[i] == 'A'){
                    hasVowel = true;
                }
                else if(word[i] == 'e' || word[i] == 'E'){
                    hasVowel = true;
                }
                else if(word[i] == 'i' || word[i] == 'I'){
                    hasVowel = true;
                }
                else if(word[i] == 'o' || word[i] == 'O'){
                    hasVowel = true;
                }
                else if(word[i] == 'u' || word[i] == 'U'){
                    hasVowel = true;
                }
                else{
                    hasConsonant = true;
                }
            }
            else{
                return false;
            }
        }
        return hasConsonant && hasVowel;
    }

    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.length();
        if(n%k != 0)
            return -1;

        int div = n / k;
        map<string, int> table;
        string highestKey = "";
        for(int i = 0; i < n; i+=k){
            string sub = word.substr(i, k);
            // cout << sub << endl;
            if(table.count(sub) > 0){
                table[sub]++;
                if(table[highestKey] < table[sub]){
                    highestKey = sub;
                }
            }
            else{
                table.insert(pair<string, int>(sub, 1));
                if(highestKey == ""){
                    highestKey = sub;
                }
            }
            // cout << "Highest: " << highestKey << endl;
        }

        int ans = 0;
        for(auto it = table.begin(); it != table.end(); it++){
            // cout << "first: " << it->first << endl;
            if(it->first != highestKey)
                ans += it->second;
        }
        return ans;
    }

    int minAnagramLength(string s) {
        int table[26];
        memset(table, 0, sizeof(int)*26);

        int n = s.length();
        int min = 0;
        for(int i = 0; i < n; i++){
            int index = s[i]-'a';
            if(table[index] == 0){
                min = i + 1;
            }
            table[index]++;
        }
        
        if(min > n/2)
            return n;

        for(int i = min; i <= n/2; i++){
            int subLength = i;
            if(n%subLength != 0)
                continue;
            
            bool failed = false;
            string subStr = s.substr(0, i);
            sort(subStr.begin(), subStr.end());

            for(int j = subLength; j < n; j+=subLength){
                string anaStr = s.substr(j, subLength);
                //cout << anaStr << endl;
                sort(anaStr.begin(), anaStr.end());
                if(subStr != anaStr){
                    failed = true;
                    break;
                }
            }

            if(failed == false)
                return subLength;
        }
        return n;
    }
};

int main(void){
    Solution s;
    cout << "First: " << endl;
    cout << s.isValid("2245IaB$2") << endl;
    cout << "Second: " << endl;
    cout << s.minimumOperationsToMakeKPeriodic("leetcoleet", 2) << endl;
    cout << "Third: " << endl;
    cout << s.minAnagramLength("leetleet") << endl;
    return 0;
}