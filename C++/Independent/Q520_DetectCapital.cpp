#include<iostream>
#include<regex>
using namespace std;

class Solution {
    bool UsingRegex(string word){
        regex reg("^([A-Z]*|[a-z]*|[A-Z][a-z]*)$");
        return regex_match(word, reg);
    }
    bool CheckCapital(string word){
        bool hasNonCapital = false;
        for(int i = 0; i < word.length(); i++){
            if(hasNonCapital){
                if(word[i] < 'a')
                    return false;
            }
            else{
                if(word[i] > 'Z'){
                    if(i > 1)
                        return false;
                    else
                        hasNonCapital = true;
                }
            }
        }
        return true;
    }
public:
    bool detectCapitalUse(string word) {
        return CheckCapital(word);
    }
};

int main(void){
    Solution s;
    cout << s.detectCapitalUse("USA") << endl;
    cout << s.detectCapitalUse("usa") << endl;
    cout << s.detectCapitalUse("uSa") << endl;
    cout << s.detectCapitalUse("Usa") << endl;
    return 0;
}