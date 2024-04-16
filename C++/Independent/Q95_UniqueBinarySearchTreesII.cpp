#include<iostream>
using namespace std;

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<TreeNode*> RecursiveSearch(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(nullptr);
        }
        else{
            for(int i = start; i < end + 1; i++){
                vector<TreeNode*> leftList = RecursiveSearch(start, i - 1);
                vector<TreeNode*> rightList = RecursiveSearch(i + 1, end);
                for(auto l : leftList){
                    for(auto r : rightList){
                        TreeNode* ans = new TreeNode();
                        ans->val = i;
                        ans->left = l;
                        ans->right = r;
                        result.push_back(ans);
                    }
                }
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return RecursiveSearch(1, n);
    }
};

int main(void){
    Solution s;
    
    return 0;
}