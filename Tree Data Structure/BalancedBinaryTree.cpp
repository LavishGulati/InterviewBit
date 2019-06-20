/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
typedef pair<bool, int> pbi;
#define f first
#define s second
#define mp make_pair

pbi IsBalancedHelper(TreeNode *A){
    if(A == NULL){
        return mp(true, 0);
    }
    
    pbi a = IsBalancedHelper(A->left);
    pbi b = IsBalancedHelper(A->right);
    
    if(!a.f || !b.f) return mp(false, -1);
    
    if(abs(a.s-b.s) <= 1){
        return mp(true, max(a.s, b.s)+1);
    }
    else return mp(false, -1);
}
 
int Solution::isBalanced(TreeNode* A) {
    return IsBalancedHelper(A).f;
}
