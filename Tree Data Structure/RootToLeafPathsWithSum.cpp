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
 
vector< vector<int> > output;
 
void PathSumHelper(TreeNode *A, int sum, int B, vector<int> &helper){
    if(A->left == NULL && A->right == NULL){
        if(A->val + sum == B){
            helper.pb(A->val);
            output.pb(helper);
            helper.pop_back();
        }
        return;
    }
    
    helper.pb(A->val);
    if(A->left != NULL){
        PathSumHelper(A->left, sum + A->val, B, helper);
    }
    if(A->right != NULL){
        PathSumHelper(A->right, sum + A->val, B, helper);
    }
    helper.pop_back();
}
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    output.clear();
    vector<int> helper;
    PathSumHelper(A, 0, B, helper);
    return output;
}
