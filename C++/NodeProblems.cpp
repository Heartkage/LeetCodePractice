#include "LeetCode.h"

using namespace std;
using namespace LeetCode;

#pragma region Q106. Construct Binary Tree from Inorder and Postorder Traversal
TreeNode* Solution106::RecursiveBuildTree(vector<int>& inorder, vector<int>& postorder, int _beginIndex, int _endIndex, int _currentPosIndex)
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

TreeNode* Solution106::buildTree(vector<int>& inorder, vector<int>& postorder) {
    return RecursiveBuildTree(inorder, postorder, 0, inorder.size(), postorder.size()-1);
}
#pragma endregion

#pragma region Q110. Balanced Binary Tree
int Solution110::recursiveCheckHeight(TreeNode *currentNode)
{
    if(currentNode == nullptr)
        return 0;
    else
    {
        int leftHeight = recursiveCheckHeight(currentNode->left);
        int rightHeight = recursiveCheckHeight(currentNode->right);

        if(leftHeight == -1 || rightHeight == -1)
            return -1;
        else if(abs(leftHeight - rightHeight) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
}
bool Solution110::isBalanced(TreeNode* root) {
    return recursiveCheckHeight(root) != -1;
}

void Solution110::test()
{
    TreeNode *first = new TreeNode(1);
    TreeNode *second = new TreeNode(2);
    TreeNode *third = new TreeNode(3);
    TreeNode *fourth = new TreeNode(4);
    //first->left = second;
    first->right = third;
    third->right = fourth;

    if(isBalanced(first))
        cout << "True" << endl;
    else
        cout << "false" << endl;
}
#pragma endregion

#pragma region Q116. Populating Next Right Pointers in Each Node
void Solution116::RecursiveConnect(Node* left, Node* right)
    {
        if(left == NULL)
            return;
        left->next = right;
        RecursiveConnect(left->left, left->right);
        RecursiveConnect(left->right, (right == NULL) ? NULL : right->left);
    }

Node* Solution116::connect(Node* root) {
    RecursiveConnect(root, nullptr);
    return root;
}
#pragma endregion

#pragma region Q117. Populating Next Right Pointers in Each Node II
Node* Solution117::RecursiveSearchNext(Node* _current, Node* _target, int _depth, int _maxDepth)
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
void Solution117::RecursiveConnectFromHead(Node* _current, int _depth)
{
    if(_current == NULL)
        return;
    m_foundNextTarge = false;
    _current->next = RecursiveSearchNext(m_root, _current, 0, _depth);
    RecursiveConnectFromHead(_current->left, _depth + 1);
    RecursiveConnectFromHead(_current->right, _depth + 1);
}

Node* Solution117::connect(Node* root) {
    m_root = root;
    RecursiveConnectFromHead(root, 0);
    return root;
}
#pragma endregion