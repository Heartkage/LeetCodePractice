#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    int solveInRecursion(int n){
        unordered_map<int, int> map;
        map.insert(pair<int, int>(0, 0));
        map.insert(pair<int, int>(1, 1));
        map.insert(pair<int, int>(2, 1));
        return recursion(map, n);
    }
    int recursion(unordered_map<int, int> &map, int n){
        if(map.find(n) != map.end())
            return map[n];
        else{
            int n_1 = recursion(map, n-1);
            int n_2 = recursion(map, n-2);
            int n_3 = recursion(map, n-3);
            map.insert(pair<int, int>(n-1, n_1));
            map.insert(pair<int, int>(n-2, n_2));
            map.insert(pair<int, int>(n-3, n_3));
            return n_1 + n_2 + n_3;
        }
    }
public:
    vector<int> table;
    Solution(){
        table = vector<int>(38, 0);
        table[0] = 0;
        table[1] = 1;
        table[2] = 1;
        table[3] = 2;
        table[4] = 4;
        table[5] = 7;
        table[6] = 13;
        table[7] = 24;
        table[8] = 44;
        table[9] = 81;
        table[10] = 149;
        table[11] = 274;
        table[12] = 504;
        table[13] = 927;
        table[14] = 1705;
        table[15] = 3136;
        table[16] = 5768;
        table[17] = 10609;
        table[18] = 19513;
        table[19] = 35890;
        table[20] = 66012;
        table[21] = 121415;
        table[22] = 223317;
        table[23] = 410744;
        table[24] = 755476;
        table[25] = 1389537;
        table[26] = 2555757;
        table[27] = 4700770;
        table[28] = 8646064;
        table[29] = 15902591;
        table[30] = 29249425;
        table[31] = 53798080;
        table[32] = 98950096;
        table[33] = 181997601;
        table[34] = 334745777;
        table[35] = 615693474;
        table[36] = 1132436852;
        table[37] = 2082876103;
    }
    int tribonacci(int n) {
        return table[n];
    }
};

int main(void){
    Solution s;
    for(int i = 0; i <= 37; i++){
        cout << "table[" << i << "] = " << s.tribonacci(i) << ";" << endl;
    }

    return 0;
}
