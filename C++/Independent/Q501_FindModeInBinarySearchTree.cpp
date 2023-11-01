#include<iostream>
#include<vector>
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
    int lastNum;
    int highestFrequency;
    int count;
    void recursiveSearch(vector<int> &ans, TreeNode* node){
        if(node == nullptr)
            return;
        recursiveSearch(ans, node->left);
        if(node->val == lastNum)
            count++;
        else if(count == 0){
            lastNum = node->val;
            count = 1;
        }
        else if (count >= highestFrequency){
            if(count > highestFrequency)
                ans.clear();
            highestFrequency = count;
            ans.push_back(lastNum);
            lastNum = node->val;
            count = 1;
        }
        recursiveSearch(ans, node->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        highestFrequency = 0;
        lastNum = -100000000;
        vector<int> ans;
        recursiveSearch(ans, root);

        if (count >= highestFrequency){
            if(count > highestFrequency)
                ans.clear();
            ans.push_back(lastNum);
        }

        return ans;
    }
};

int main(void){
    return 0;
}