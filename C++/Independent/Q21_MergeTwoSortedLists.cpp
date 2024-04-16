#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *current;
        if(list1 && list2){
            current = list2->val > list1->val ? list1 : list2;
            list2 = list2->val > list1->val ? list2 : list1;
            list1 = current;
        }
        else if(list1 == nullptr)
            return list2;
            
        
        while(current && list2){
            if(current->next){
                if(current->next->val > list2->val){
                    // ListNode *temp = list2;
                    // list2 = current->next;
                    // current->next = temp;
                    swap(current->next, list2);
                }
            }
            else{
                current->next = list2;
                break;
            }
            current = current->next;
        }
        return list1;
    }
};

int main(void){
    ListNode *node = new ListNode();
    ListNode *head1 = node;
    node->val = 1;

    node->next = new ListNode();
    node = node->next;
    node->val = 2;


    node->next = new ListNode();
    node = node->next;
    node->val = 4;

    ListNode *node2 = new ListNode();
    ListNode *head2 = node2;
    node2->val = 1;

    node2->next = new ListNode();
    node2 = node2->next;
    node2->val = 3;


    node2->next = new ListNode();
    node2 = node2->next;
    node2->val = 4;

    Solution s;
    s.mergeTwoLists(head1, head2);

    return 0;
}