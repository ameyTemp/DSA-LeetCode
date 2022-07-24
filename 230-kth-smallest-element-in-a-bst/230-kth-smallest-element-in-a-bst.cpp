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
    int min_ele=INT_MAX;
    vector<int> nums;
public:
    void check(TreeNode* node){
        if(node==NULL)
            return;
        if(node!=NULL){
            nums.push_back(node->val);
        }
        check(node->right);
        check(node->left);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        check(root);
        sort(nums.begin(),nums.end());
        return nums[k-1];
    }
};