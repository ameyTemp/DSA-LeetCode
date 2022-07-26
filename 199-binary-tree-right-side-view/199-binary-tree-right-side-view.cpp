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
    void preorder(TreeNode* root,int level,vector<int>& ans){
        if(root==NULL)
            return;
        if(ans.size()<level)
            ans.push_back(root->val);
        preorder(root->right,level+1,ans);
        preorder(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // preorder(root,1,ans);
        // cout<<height(root)<<endl;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* right = NULL;
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode * temp = q.front();
                q.pop();
                if(temp!=NULL){
                    right = temp;
                    q.push(temp->left);
                    q.push(temp->right);
                }   
            }
            if(right!=NULL)
                ans.push_back(right->val);
        }
        return ans;
    }
};