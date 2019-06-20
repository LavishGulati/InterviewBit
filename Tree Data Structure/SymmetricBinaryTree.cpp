/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool IsSymmetricHelper(TreeNode *A, TreeNode *B){
    if(A == NULL && B == NULL) return true;
    else if(A == NULL) return false;
    else if(B == NULL) return false;
    
    if(A->val != B->val) return false;
    
    return IsSymmetricHelper(A->left, B->right) && IsSymmetricHelper(A->right, B->left);
} 

int Solution::isSymmetric(TreeNode* A) {
    return IsSymmetricHelper(A, A) ? 1 : 0;
}
