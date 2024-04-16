#include<iostream>
#include<vector>
#include<map>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node *> nodes;
        map<Node *, int> maps;

        Node *current = head;
        int index = 0;
        while(current != NULL)
        {
            Node *newNode = new Node(current->val);
            nodes.push_back(newNode);
            maps.insert(pair<Node *, int>(current, index));

            current = current->next;
            index++;
        }

        current = head;
        for(int i = 0; i < nodes.size(); i++)
        {
            if((i + 1) < nodes.size())
                nodes[i]->next = nodes[i+1];
            if(current->random != nullptr)
                (nodes[i])->random = nodes[maps[current->random]];

            current = current->next;
        }

        if(nodes.size() > 0)
            return nodes[0];
        else
            return NULL;
    }
};

int main(void)
{
    Node *first = new Node(6);
    Node *second = new Node(7);
    Node *third = new Node(8);

    first->next = second;
    second->next = third;
    third->random = second;
    first->random = third;

    Node *current = first;
    while(current != nullptr)
    {
        printf("currentNum = %d\n", current->val);
        if(current->random != nullptr)
            printf("randomNum = %d\n", current->random->val);
        current = current->next;
    }
    printf("---------------------\n");

    Solution s;
    Node *newNode = s.copyRandomList(first);

    current = newNode;
    while(current != nullptr)
    {
        printf("currentNum = %d\n", current->val);
        if(current->random != nullptr)
            printf("randomNum = %d\n", current->random->val);
        current = current->next;
    }

    return 0;
}