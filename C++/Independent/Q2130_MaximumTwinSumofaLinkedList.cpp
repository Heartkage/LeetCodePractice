#include<iostream>
#include<deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        deque<int> dq;
        ListNode *cur = head;
        while(cur != NULL){
            dq.push_back(cur->val);
            cur = cur->next;
        }
        int ans = -1;
        while(!dq.empty()){
            int temp = dq.front() + dq.back();
            if(temp > ans)
                ans = temp;
            dq.pop_front();
            dq.pop_back();
        }
        return ans;
    }
};

int main(void){
    Solution s;
    ListNode *node2 = new ListNode(1);
    ListNode *node1 = new ListNode(100, node2);
    ListNode *head = node1;

    cout << s.pairSum(head) << endl;
    return 0;
}