#include<iostream>
#include<vector>

using namespace std;

class Solution {
    vector<vector<string> > answers;
    vector<string> currentAnswer;

    bool IsPalindrome(string s){
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp.compare(s) == 0;
    }

    void RecursiveSearch(string s){
        if(s.length() == 0){
            answers.push_back(currentAnswer);
            return;
        }

        for(int i = 0; i < s.length(); i++){
            string frontString = s.substr(0, i+1);
            if(IsPalindrome(frontString)){
                currentAnswer.push_back(frontString);
                RecursiveSearch(s.substr(i+1));
                currentAnswer.pop_back();
            }
        }
    }

public:
    vector<vector<string> > partition(string s) {
        answers.clear();
        RecursiveSearch(s);
        return answers;
    }
};

int main(void){

    Solution s;
    vector<vector<string> > answer = s.partition("aaaaaaaaaa");
    cout << "answers: " << endl;
    for(int i = 0; i < answer.size(); i++){
        for(int j = 0; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}