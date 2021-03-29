#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
#include<stack>

using namespace std;

namespace Support
{
    class SupportBase
    {
        time_t m_startTime;
    public:
        virtual void test();
        virtual void endTest();
    };
}

using namespace Support;

namespace NodeProblem
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

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
}
using namespace NodeProblem;

namespace LeetCode
{ 
    class Solution42 : public SupportBase {
    public:
        int trap(vector<int>&);
        void test() override;
    };

    class Solution60 : public SupportBase {
        int findAvailableIndex(vector<bool>&, int);
    public:
        string getPermutation(int n, int k);
        void test() override;
    };

    class Solution106
    {
        TreeNode* RecursiveBuildTree(vector<int>&, vector<int>&, int, int, int);
    public:
        TreeNode* buildTree(vector<int>&, vector<int>&);
    };

    class Solution110
    {
        int recursiveCheckHeight(TreeNode *);
    public:
        bool isBalanced(TreeNode*);

        void test();
    };

    class Solution116
    {
        void RecursiveConnect(Node*, Node*);
    public:
        Node* connect(Node*);
    };

    class Solution117
    {
        bool m_foundNextTarge;
        Node* m_root;
        Node* RecursiveSearchNext(Node*, Node*, int, int);
        void RecursiveConnectFromHead(Node*, int _depth);
    public:
        Node* connect(Node*);
    };

    class Solution143
    {  
    public:
        void reorderList(ListNode*);
    };
    
    class Solution147
    {
        ListNode* reverseList(ListNode *head);
    public:
        ListNode* insertionSortList(ListNode* head);
        void test();
    };

    class Solution148
    {
        int Partition(ListNode* leftHead, int leftIndex, int rightIndex);
        void QuickSort(ListNode* leftHead, int leftIndex, int rightIndex);
    public:
        ListNode* sortList(ListNode* head);
    };

    class Solution160 {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    };

    class Solution173
    {
        queue<int> m_numberQueue;
        void TraverseTree(TreeNode* current);
    public:
        BSTIterator(TreeNode* root);
        int next();
        bool hasNext();
    };
}