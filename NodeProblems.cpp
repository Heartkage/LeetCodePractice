#include<iostream>
#include<vector>
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q116. Populating Next Right Pointers in Each Node
// Q117. Populating Next Right Pointers in Each Node II
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

// Q106. Construct Binary Tree from Inorder and Postorder Traversal
class Solution106 {
private:
    TreeNode* RecursiveBuildTree(vector<int>& inorder, vector<int>& postorder, int _beginIndex, int _endIndex, int _currentPosIndex)
    {
        if(_currentPosIndex < 0 || _currentPosIndex >= postorder.size())
            return NULL;
        
        //cout << "[Begin]: " << _beginIndex << ", [End]: " << _endIndex << ", [current]: " << _currentPosIndex << endl; 
        for(int i = _endIndex-1; i >= _beginIndex; i--)
        {
            if(inorder[i] == postorder[_currentPosIndex])
            {
                TreeNode* newNode = new TreeNode();
                newNode->val = inorder[i];
                //cout << "Created -> " << newNode->val << endl;
                newNode->left = RecursiveBuildTree(inorder, postorder, _beginIndex, i, _currentPosIndex - (_endIndex - i));
                newNode->right = RecursiveBuildTree(inorder, postorder, i, _endIndex, _currentPosIndex - 1);
                return newNode;
            }
        }

        return NULL;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return RecursiveBuildTree(inorder, postorder, 0, inorder.size(), postorder.size()-1);
    }
};

int main()
{
    vector<int> inorder = {24, 11, 9, 23, 12, 26, 3, 15, 20, 7};
    vector<int> posorder = {24, 11, 23, 26, 12, 9, 15, 7, 20, 3};

    Solution106 s;
    s.buildTree(inorder, posorder);
    
    return 0;
}