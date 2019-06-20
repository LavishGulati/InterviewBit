/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    TreeNode *temp = A, *ap;
    while(!(temp->left == NULL && temp->right == NULL)){
        if(temp->left != NULL){
            ap = temp->left;
            while(ap->right != NULL) ap = ap->right;
            ap->right = temp->right;
            temp->right = temp->left;
            temp->left = NULL;
        }
        temp = temp->right;
    }
    return A;
}
