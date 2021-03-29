#include "LeetCode.h"

using namespace std;
using namespace LeetCode;
using namespace NodeProblem;

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
            return (leftHeight < rightHeight) ? rightHeight + 1 : leftHeight + 1;
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

#pragma region Q143. Reorder List
void Solution143::reorderList(ListNode* head)
{
    vector<ListNode*> reorder;
    ListNode *current = head;
    while(current != nullptr)
    {
        reorder.push_back(current);
        current = current->next;
    }

    int frontIndex = 1;
    int backIndex = reorder.size()-1;
    current = head;
    for(int i = 1; i < reorder.size(); i++)
    {
        if(i & 1)
        {
            current->next = reorder[backIndex];
            backIndex--;
            current = current->next;
        }
        else
        {
            current->next = reorder[frontIndex];
            current = current->next;
            frontIndex++;
        }
    }
    if(current != nullptr)
        current->next = nullptr;
}
#pragma endregion

#pragma region Q147. Insertion Sort List
ListNode* Solution147::reverseList(ListNode* head)
{
    ListNode* current = head;
    ListNode* next = current->next;
    current->next = nullptr;
    while(next)
    {
        ListNode* nextNext = next->next;
        next->next = current;
        current = next;
        next = nextNext;
    }

    return current;
}

ListNode* Solution147::insertionSortList(ListNode* head)
{
    if(head == nullptr)
        return nullptr;

    ListNode *end = head;
    ListNode *nextNode = head->next;
    end->next = nullptr;
    while(nextNode)
    {
        ListNode *current = nextNode;
        nextNode = nextNode->next;
        current->next = nullptr;

        ListNode *lastNode = nullptr;
        ListNode *currentEnd = end;
        do
        {
            if(current->val > currentEnd->val)
            {
                if(lastNode != nullptr)
                    lastNode->next = current;
                else
                    end = current;
                    
                current->next = currentEnd;
                break;
            }
            else
            {
                lastNode = currentEnd;
                currentEnd = currentEnd->next;
                if(currentEnd == nullptr)
                    lastNode->next = current;
            }
        } while (currentEnd);
    }
    
    return reverseList(end);
}
void Solution147::test()
{
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(1);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(3);

    //a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    ListNode *head = insertionSortList(a);
    ListNode *current = head;
    while(current)
    {
        cout << current->val << endl;
        current = current->next;
    }
}
#pragma endregion

#pragma region Q160. Intersection of Two Linked Lists
ListNode* Solution160::getIntersectionNode(ListNode *headA, ListNode *headB) {
    int length = 0;
    ListNode *current = headA;
    while(current != nullptr)
    {
        length++;
        current = current->next;
    }
    current = headB;
    while(current != nullptr)
    {
        length--;
        current = current->next;
    }

    if(length > 0)
        while(length--) headA = headA->next;
    else
        while(length++) headB = headB->next;

    while(headA)
    {
        if(headA == headB)
            return headA;
        else
        {
            headA = headA->next;
            headB = headB->next;
        }
    }
    return nullptr;
}
#pragma endregion 

#pragma region Q173. Binary Search Tree Iterator
void Solution173::TraverseTree(TreeNode* current){
    if(current == nullptr)
        return;
    
    TraverseTree(current->left);
    m_numberQueue.push(current->val);
    TraverseTree(current->right);
}

Solution173::BSTIterator(TreeNode* root) {
    TraverseTree(root);
}

int Solution173::next()
{
    int val = m_numberQueue.front();
    m_numberQueue.pop();
    return val;
}

bool Solution173::hasNext()
{
    return !m_numberQueue.empty();
}
#pragma endregion
