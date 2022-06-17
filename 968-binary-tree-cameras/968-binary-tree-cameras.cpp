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
    // 0 - leaf node
    // 1 - parent of leaf node with camera
    // 2 - covered without camera
    int res;
    int camera(TreeNode* root){
        if(!root)
           return 2;
        int left = camera(root->left);
        int right =  camera(root->right);
        if(left==0 or right==0){
            res++;
            return 1;
        }
        if(left==1 or right==1)
            return 2;
        else
            return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(camera(root)==0)
            return 1+res;
        else
            return res;
    }
};