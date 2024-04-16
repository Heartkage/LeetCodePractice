#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int> >& trust) {
        bool trustSomeone[n+1];
        int trustCount[n+1];
        memset(trustSomeone, false, n+1);
        memset(trustCount, 0, sizeof(int)*(n+1));

        for(int i = 0; i < trust.size(); i++){
            trustSomeone[trust[i][0]] = true;
            trustCount[trust[i][1]]++;
        }

        for(int i = 1; i < n+1; i++){
            if((trustCount[i] == n-1) && trustSomeone[i] == false)
                return i;
        }
        return -1;
    }
};

int main(void){
    vector<vector<int> > trusts;
    vector<int> trust;
    trust.push_back(1);
    trust.push_back(2);
    trusts.push_back(trust);
    
    trust.clear();
    trust.push_back(3);
    trust.push_back(1);
    trusts.push_back(trust);

    trust.clear();
    trust.push_back(3);
    trust.push_back(2);
    trusts.push_back(trust);

    Solution s;
    cout << s.findJudge(3, trusts) << endl;

    return 0;
}