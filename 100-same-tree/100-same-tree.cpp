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
bool dfs(TreeNode *p,TreeNode *q){
    if(p==NULL and q==NULL)
        return true;
    if(p==NULL or q==NULL)
        return false;
    if(p->val!=q->val)
        return false;
    return dfs(p->right,q->right) and dfs(p->left,q->left);
}
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};