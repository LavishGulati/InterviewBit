/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define pb push_back

void IT(TreeNode *root, vector<int> &output){
    if(root == NULL) return;
    
    IT(root->left, output);
    output.pb(root->val);
    IT(root->right, output);
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> output;
    IT(A, output);
    return output;
}
