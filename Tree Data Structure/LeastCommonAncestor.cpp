/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool find(TreeNode *A, int x){
    if(A == NULL) return false;
    
    if(A->val == x) return true;
    
    return find(A->left, x) || find(A->right, x);
}

int helper(TreeNode *A, int B, int C){
    if(A == NULL) return -1;
    
    if(A->val == B || A->val == C) return A->val;
    
    int left = helper(A->left, B, C);
    int right = helper(A->right, B, C);
    
    if(left == -1 && right == -1) return -1;
    else if(left != -1 && right != -1) return A->val;
    else if(left == -1) return right;
    else return left;
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(!(find(A, B) && find(A, C))) return -1;
    
    return helper(A, B, C);
}
