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
    int pre_ind = 0;
    int post_ind = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    { 
        TreeNode* curr = new TreeNode(preorder[pre_ind]);
        pre_ind++;

        if(curr->val != postorder[post_ind])
        {
            curr->left = constructFromPrePost(preorder, postorder);
        }

        if(curr->val != postorder[post_ind])
        {
            curr->right = constructFromPrePost(preorder, postorder);
        }

        post_ind++;

        return curr;
    }
};