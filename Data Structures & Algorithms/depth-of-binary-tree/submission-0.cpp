/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    void quest(TreeNode* root, int& ans, int count){
        if(root == NULL) {
            ans = max(ans, count);
            return;
        }
        count++;
        quest(root->left,ans,count);
        quest(root->right,ans, count);
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = INT_MIN;
        int count =0;
        quest(root,ans, count);
        return ans;
    }
};
