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
    bool dfs(TreeNode* l,TreeNode* r){
        // cout<<r->val<<l->val<<endl;
        if(l==NULL and r==NULL)
            return true;
        if(r==NULL or l==NULL)
            return false;
        if(r->val!=l->val)
            return false;
        
        return dfs(l->right,r->left) and dfs(l->left,r->right);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};