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
 
int PathSum(TreeNode *A){
    if(A == NULL) return 0;
    
    int x = PathSum(A->left);
    int y = PathSum(A->right);
    
    int a = max(x+y+A->val, x+A->val);
    a = max(a, y+A->val);
    a = max(a, A->val);
    answer = max(a, answer);
    
    return max(x+A->val, max(y+A->val, A->val));
}
 
int Solution::maxPathSum(TreeNode* A) {
    answer = INT_MIN;
    PathSum(A);
    return answer;
}
