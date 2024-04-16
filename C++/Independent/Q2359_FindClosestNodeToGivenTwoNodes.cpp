#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> checkList1(n, false);
        vector<bool> checkList2(n, false);
        bool run1 = true;
        bool run2 = true;
        bool foundNode2 = false;
        while(run1 || run2){
            int lastNode1;
            if(run1){
                if(node1 == -1)
                    run1 = false;
                else if(checkList1[node1])
                    run1 = false;
                else{
                    checkList1[node1] = true;
                    lastNode1 = node1;
                    node1 = edges[node1];
                }
            }

            if(run2){
                if(node2 == -1)
                    run2 = false;
                else if(checkList1[node2])
                    foundNode2 = true;
                else if(checkList2[node2])
                    run2 = false;
                else{
                    checkList2[node2] = true;
                    node2 = edges[node2];
                }
            }

            if(checkList2[lastNode1]){
                if(foundNode2)
                    return min(node2, lastNode1);
                else
                    return lastNode1;
            }
            else if(foundNode2)
                return node2;
        }
        return -1;
    }
};

int main(void){
    vector<int> edges;
    edges.push_back(2);
    edges.push_back(0);
    edges.push_back(0);

    Solution s;
    cout << s.closestMeetingNode(edges, 2, 0) << endl;

    return 0;
}