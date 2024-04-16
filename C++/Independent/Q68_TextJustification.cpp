#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int previousIndex = 0;
        int n = words.size();
        int currentLength = -1;
        for(int i = 0; i < n; i++){
            int predictSize = currentLength + 1 + words[i].size();
            if(predictSize > maxWidth){
                int gapCount = i - previousIndex - 1;
                int spaceInEach = (gapCount > 0) ? (maxWidth - (currentLength - gapCount)) / gapCount : 0;
                int leftoverSpace = (gapCount > 0) ? (maxWidth - (currentLength - gapCount)) % gapCount : maxWidth - currentLength;
                string newLine = "";
                for(int j = previousIndex; j < i; j++){
                    int appendSpaces = leftoverSpace;
                    if(j < (i-1)){
                        appendSpaces = spaceInEach;
                        if(leftoverSpace > 0){
                            appendSpaces += 1;
                            leftoverSpace--;
                        }
                    }
                    newLine += words[j];
                    if(appendSpaces > 0)
                        newLine.append(appendSpaces, ' ');
                }
                ans.push_back(newLine);
                previousIndex = i;
                currentLength = words[i].size();
            }
            else if(predictSize == maxWidth){
                string newLine = words[previousIndex];
                for(int j = previousIndex + 1; j < i + 1; j++)
                    newLine += " " + words[j];
                ans.push_back(newLine);
                previousIndex = i + 1;
                currentLength = -1;
            }
            else
                currentLength = predictSize;

            // if is the last string in list and it has not been insert yet
            if(i == (n-1) && previousIndex <= i){
                string newLine = words[previousIndex];
                for(int j = previousIndex + 1; j <= i; j++)
                    newLine += " " + words[j];
                if(maxWidth - currentLength > 0)
                    newLine.append(maxWidth - currentLength, ' ');
                ans.push_back(newLine);
            }
        }
        return ans;
    }
};

int main(void){
    vector<string> input;
    input.push_back("ask");
    input.push_back("not");
    input.push_back("what");
    input.push_back("your");
    input.push_back("country");
    input.push_back("can");
    input.push_back("do");
    input.push_back("for");
    input.push_back("you");
    input.push_back("ask");
    input.push_back("whate");
    input.push_back("you");
    input.push_back("can");
    input.push_back("do");
    input.push_back("for");
    input.push_back("your");
    input.push_back("country");


    Solution s;
    vector<string> ans = s.fullJustify(input, 16);
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}