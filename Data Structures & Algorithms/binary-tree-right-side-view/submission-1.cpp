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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        vector<int> ans;
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
               TreeNode* popped = que.front();
               que.pop();
               if(i==size-1) ans.push_back(popped->val);
                 if(popped->left) que.push(popped->left);
                 if(popped->right) que.push(popped->right);
            }
        }
        return ans;
    }
};
