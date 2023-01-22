#include<iostream>
#include<vector>

using namespace std;

class Solution {
    bool IsPalindrome(string &s){
        int j = s.length() - 1;
        for(int i = 0; i < j; i++, j--){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }

    void RecursiveSearch(int index, const string &s, vector<vector<string> > &answers, vector<string> &currentAnswer){
        int n = s.length();
        if(index == n){
            answers.push_back(currentAnswer);
            return;
        }

        for(int i = index; i < n; i++){
            string frontString = s.substr(index, i-index+1);
            if(IsPalindrome(frontString)){
                currentAnswer.push_back(frontString);
                RecursiveSearch(i+1, s, answers, currentAnswer);
                currentAnswer.pop_back();
            }
        }
    }

public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > answers;
        vector<string> currentAnswer;
        RecursiveSearch(0, s, answers, currentAnswer);
        return answers;
    }
};

int main(void){

    Solution s;
    vector<vector<string> > answer = s.partition("aab");
    cout << "answers: " << endl;
    for(int i = 0; i < answer.size(); i++){
        for(int j = 0; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}