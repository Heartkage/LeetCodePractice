#include<iostream>
#include<cstring>
#include<vector>
#include<deque>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;

        vector<deque<string> > check;
        vector<unordered_map<string, int> > check2;
        unordered_map<string, int> myMap;
        int wordLength = words[0].size();
        int totalLength = wordLength * words.size();

        // Create Map Table
        for(int i = 0; i < words.size(); i++){
            if(myMap.find(words[i]) == myMap.end()){
                myMap.insert(pair<string, int>(words[i], 1));
            }
            else{
                myMap[words[i]]++;
            }
        }

        for(int i = 0; i < s.size(); i++){
            int previousCheckIndex = i % wordLength;
            string sub = s.substr(i, wordLength);
            bool canInsert = false;
            bool canRemove = false;
            string canInsertString = "";
            do{
                if(canRemove){
                    if(canInsertString.compare("") == 0){
                        check2[previousCheckIndex] = myMap;
                        check[previousCheckIndex].clear();
                    }
                    else{
                        bool foundSub = false;
                        while(foundSub == false){
                            if(check[previousCheckIndex].front() == canInsertString)
                                foundSub = true;

                            check2[previousCheckIndex][check[previousCheckIndex].front()]++;
                            check[previousCheckIndex].pop_front();
                        } 
                    }
                }

                if(i < wordLength){
                    deque<string> deque;
                    unordered_map<string, int> map(myMap);
                    check.push_back(deque);
                    check2.push_back(map);
                }

                if(check2[previousCheckIndex].find(sub) != check2[previousCheckIndex].end()){
                    canInsertString = sub;
                    if(check2[previousCheckIndex][sub] > 0){
                        check[previousCheckIndex].push_back(sub);
                        check2[previousCheckIndex][sub]--;
                        canInsert = true;
                        break;
                    }
                }

                canRemove = true;
            }while((check[previousCheckIndex].empty() == false) && canInsert == false);

            if(canInsert){
                if(check[previousCheckIndex].size() == words.size()){
                    int firstIndex = i - (totalLength - wordLength);
                    answer.push_back(firstIndex);
                    check2[previousCheckIndex][check[previousCheckIndex].front()]++;
                    check[previousCheckIndex].pop_front();
                }
            }
        }
        return answer;
    }
};

int main(void){
    Solution s;
    vector<string> words;
    words.push_back("ab");
    words.push_back("ba");
    words.push_back("ab");
    words.push_back("ba");
    vector<int> answer = s.findSubstring("abaababbaba", words);
    cout << "Answers: " << endl;
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    return 0;
}