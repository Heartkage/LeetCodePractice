#include<iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dfs(TreeNode* node, int val){
        if(node == nullptr)
            return 0;
        else{
            val = (val ^ (1 << node->val));
            if(node->left == nullptr && node->right == nullptr){
                if(val == 0)
                    return 1;
                else if((val & (val - 1)) == 0)
                    return 1;
                else
                    return 0;
            }
            else
                return dfs(node->left, val) + dfs(node->right, val);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
};

int main(void){
    TreeNode node = new TreeNode();

    Solution s;
    cout << s.pseudoPalindromicPaths(node) << endl;

    return 0;
}