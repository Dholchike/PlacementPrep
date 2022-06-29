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
    bool isSame(TreeNode *p, TreeNode *q){
        if(p == nullptr && q== nullptr){
            return true;
        }
        if(p &&!q || !p && q){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        
        return isSame(p->right, q->left) && isSame(p->left, q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        return isSame(root->left, root->right);
    }
};