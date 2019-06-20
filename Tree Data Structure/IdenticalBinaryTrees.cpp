/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool IsSameTreeHelper(TreeNode *A, TreeNode *B){
    if(A == NULL && B == NULL) return true;
    else if(A == NULL) return false;
    else if(B == NULL) return false;
    
    if(A->val != B->val) return false;
    
    return IsSameTreeHelper(A->left, B->left) && IsSameTreeHelper(A->right, B->right);
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return IsSameTreeHelper(A, B);
}
