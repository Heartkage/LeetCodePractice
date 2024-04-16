#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    void printBoard(vector<vector<int> > &board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----end of board----" << endl;
    }
    void printBoardInLine(vector<int> &board){
        for(int i = 0; i < board.size(); i++){
            cout << board[i] << " ";
        }
        cout << endl << "----end of boardInLine----" << endl;
    }
public:
    int snakesAndLadders(vector<vector<int> >& board) {
        int n = board.size();
        vector<int> boardInLine(n*n+1);
        bool isForward = true;
        int currentIndex = 1;
        for(int i = n-1; i > -1; --i){
            if(!isForward)
                reverse(board[i].begin(), board[i].end());
            for(int j = 0; j < n; j++)
                boardInLine[currentIndex++] = board[i][j];
            isForward = !isForward;
        }
        //printBoardInLine(boardInLine);
        n *= n;
        queue<int> bfs;
        boardInLine[1] = -2;
        bfs.push(1);
        int res = 0;
        while(!bfs.empty()){
            ++res;
            int total = bfs.size();
            while(total--){
                int currentStep = bfs.front();
                int updateStep = 0;
                bfs.pop();
                for(int step = 1; step < 7; step++){
                    int nextStep = boardInLine[currentStep+step];
                    if(nextStep == -2)
                        continue;
                    else if(currentStep+step == n)
                        return res;
                    else if(nextStep == n)
                        return res;
                    else if(nextStep != -1)
                        bfs.push(nextStep);
                    else
                        updateStep = step;

                    boardInLine[currentStep+step] = -2;
                }

                if(updateStep > 0)
                    bfs.push(currentStep + updateStep);
            }
        }
        return -1;
    }
};

int main(void){
    vector<vector<int> > board;
    const int n = 6;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++)
            row.push_back(-1);
        board.push_back(row);
    }
    board[5][1] = 15;
    board[3][1] = 35;
    board[3][4] = 13;

    Solution s;
    cout << s.snakesAndLadders(board) << endl;

    return 0;
}