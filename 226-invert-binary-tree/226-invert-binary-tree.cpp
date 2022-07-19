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
    void invert(TreeNode* temp){
        if(!temp or (!temp->left and !temp->right))
            return;
        if(temp->left and temp->right){
            TreeNode* node = temp->left;
            temp->left = temp->right;
            temp->right = node;
            invert(temp->left);
            invert(temp->right);
        }else if(temp->left){
            temp->right = temp->left;
            temp->left=NULL;
            invert(temp->right);
        }else if(temp->right){
            temp->left=temp->right;
            temp->right=NULL;
            invert(temp->left);
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp = root;
        invert(temp);
        return root;
    }
};