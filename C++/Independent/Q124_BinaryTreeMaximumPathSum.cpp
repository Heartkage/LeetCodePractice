#include<iostream>
#include<climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {

    // <selfMaxValue, includeParentMax>
    pair<int, int> RecursiveSearch(TreeNode* node)
    {
        if(node == NULL)
            return pair<int, int>(-10000, -10000);
        
        pair<int, int> leftValues = RecursiveSearch(node->left);
        pair<int, int> rightValues = RecursiveSearch(node->right);

        //---Find Self Max---//
        // compare child's each selfMax
        int selfMax = max(leftValues.first, rightValues.first);
        selfMax = max(selfMax, leftValues.second);
        selfMax = max(selfMax, rightValues.second);
        // compare from both children includeParentMax
        selfMax = max(selfMax, leftValues.second + node->val + rightValues.second);

        //---Find Include Parent Max---//
        int includeMax = max(node->val, node->val+leftValues.second);
        includeMax = max(includeMax, node->val+rightValues.second);

        return pair<int, int>(selfMax, includeMax);
    }
public:
    int maxPathSum(TreeNode* root) {
        pair<int, int> answer = RecursiveSearch(root);
        if(answer.first > answer.second)
            return answer.first;
        else
            return answer.second;
    }
};

int main(void)
{

    return 0;
}