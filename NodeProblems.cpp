#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:
    // Q116
    void RecursiveConnect(Node* left, Node* right)
    {
        if(left == NULL)
            return;
        left->next = right;
        RecursiveConnect(left->left, left->right);
        RecursiveConnect(left->right, (right == NULL) ? NULL : right->left);
    }

public:
    // Q116
    public:
    Node* connect(Node* root) {
        RecursiveConnect(root, NULL);
        return root;
    }
};

int main()
{

    return 0;
}