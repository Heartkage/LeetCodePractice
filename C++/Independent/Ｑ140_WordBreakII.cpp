#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

class Solution {
    vector<string> answers;
    string currentAnswer;
    set<string> book;

    void RecursiveSearch(string s){
        if(s.length() == 0){
            answers.push_back(currentAnswer);
            return;
        }

        for(int i = 0; i < s.length(); i++){
            string frontString = s.substr(0, i+1);
            if(book.find(frontString) != book.end()){
                int length = frontString.length();
                if(currentAnswer.length() == 0){
                    currentAnswer.append(frontString);
                }
                else{
                    length++;
                    currentAnswer.append(" ");
                    currentAnswer.append(frontString);
                }
                RecursiveSearch(s.substr(i+1));
                currentAnswer.erase(currentAnswer.length()-length, length);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        book.clear();
        answers.clear();
        for(int i = 0; i < wordDict.size(); i++)
            book.insert(wordDict[i]);

        RecursiveSearch(s);
        return answers;
    }
};

int main(void){


    vector<string> test;
    test.push_back("cat");
    test.push_back("cats");
    test.push_back("and");
    test.push_back("sand");
    test.push_back("dog");
    Solution s;
    vector<string> answer = s.wordBreak("catsanddog", test);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }

    return 0;
}