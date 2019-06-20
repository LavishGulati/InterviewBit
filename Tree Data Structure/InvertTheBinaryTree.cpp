/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *invert(TreeNode *A){
    if(A == NULL) return NULL;
    
    TreeNode *LeftChild, *RightChild;
    LeftChild = invert(A->left);
    RightChild = invert(A->right);
    
    A->left = RightChild;
    A->right = LeftChild;
    return A;
}
 
TreeNode* Solution::invertTree(TreeNode* A) {
    return invert(A);
}
