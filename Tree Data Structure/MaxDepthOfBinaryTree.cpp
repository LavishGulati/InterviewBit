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
 
void MaxDepthHelper(TreeNode *A, int h){
    if(A == NULL){
        answer = max(answer, h);
        return;
    }
    
    MaxDepthHelper(A->left, h+1);
    MaxDepthHelper(A->right, h+1);
}
 
int Solution::maxDepth(TreeNode* A) {
    answer = 0;
    MaxDepthHelper(A, 0);
    return answer;
}
