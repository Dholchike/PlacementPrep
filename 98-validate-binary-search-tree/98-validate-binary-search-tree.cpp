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
    bool validBSTchecker(TreeNode *root, long  smol, long  large){
        if(root == nullptr){
           return true;
        }
        
        if(root->val <= smol || root->val >= large){
            // cases jahan pe false dena chahiye
            return false;
        }
     
        return validBSTchecker(root->left, smol, root->val) && validBSTchecker(root->right, root->val , large); 
    }
    
    bool isValidBST(TreeNode* root) {
        
       // range of values se check kro
        
        return validBSTchecker(root, LONG_MIN, LONG_MAX);
        
    }
};