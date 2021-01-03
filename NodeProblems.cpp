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
    // Q116. Populating Next Right Pointers in Each Node
    void RecursiveConnect(Node* left, Node* right)
    {
        if(left == NULL)
            return;
        left->next = right;
        RecursiveConnect(left->left, left->right);
        RecursiveConnect(left->right, (right == NULL) ? NULL : right->left);
    }

    // Q117. Populating Next Right Pointers in Each Node II
    bool m_foundNextTarge;
    Node* m_root;
    Node* RecursiveSearchNext(Node* _current, Node* _target, int _depth, int _maxDepth)
    {
        if(_current == NULL)
            return NULL;
        else if(_depth >= _maxDepth)
        {
            if(_current == _target)
            {
                m_foundNextTarge = true;
                return NULL;
            }
            else if(m_foundNextTarge)
                return _current;
            else
                return NULL;
        }
        else
        {
            Node* temp = RecursiveSearchNext(_current->left, _target, _depth + 1, _maxDepth);
            return (temp == NULL) ? RecursiveSearchNext(_current->right, _target, _depth + 1, _maxDepth) : temp;
        }
    }
    void RecursiveConnectFromHead(Node* _current, int _depth)
    {
        if(_current == NULL)
            return;
        m_foundNextTarge = false;
        _current->next = RecursiveSearchNext(m_root, _current, 0, _depth);
        RecursiveConnectFromHead(_current->left, _depth + 1);
        RecursiveConnectFromHead(_current->right, _depth + 1);
    }

public:
    // Q116, Q117
    public:
    Node* connect(Node* root) {
        m_root = root;
        RecursiveConnectFromHead(root, 0);
        return root;
    }
    
};

int main()
{
    Node* main = new Node();
    Node* left = new Node();
    Node* right = new Node();

    main->left = left;
    main->right = right;

    Solution s;
    s.connect(main);

    return 0;
}