/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int answer;

void MinDepthHelper(TreeNode *A, int h){
    if(A->left == NULL && A->right == NULL){
        answer = min(answer, h+1);
    }
    
    if(A->left != NULL) MinDepthHelper(A->left, h+1);
    if(A->right != NULL) MinDepthHelper(A->right, h+1);
}

int Solution::minDepth(TreeNode* A) {
    answer = INT_MAX;
    MinDepthHelper(A, 0);
    return answer;
}
