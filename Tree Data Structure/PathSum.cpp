/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool HasPathSumHelper(TreeNode *A, int sum, int B){
    if(A->left == NULL && A->right == NULL){
        if(sum == B) return true;
        else return false;
    }
    
    if(A->left != NULL && HasPathSumHelper(A->left, sum + A->left->val, B)){
        return true;
    }
    if(A->right != NULL && HasPathSumHelper(A->right, sum + A->right->val, B)){
        return true;
    }
    
    return false;
}
 
int Solution::hasPathSum(TreeNode* A, int B) {
    return HasPathSumHelper(A, A->val, B) ? 1 : 0;
}
