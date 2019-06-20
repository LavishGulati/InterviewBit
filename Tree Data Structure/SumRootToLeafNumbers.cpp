/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define MOD 1003
typedef long long ll;

ll sum;
 
void SumNumbersHelper(TreeNode *A, string s){
    if(A->left == NULL && A->right == NULL){
        char c = A->val + '0';
        s += c;
        ll x = 0;
        ll power = 1;
        for(int i = s.length()-1; i >= 0; i--){
            x = (x+((power*(s[i]-'0'))%MOD))%MOD;
            power = (power*10)%MOD;
        }
        sum = (sum+x)%MOD;
        return;
    }
    
    char c = A->val + '0';
    if(A->left != NULL){
        SumNumbersHelper(A->left, s+c);
    }
    if(A->right != NULL){
        SumNumbersHelper(A->right, s+c);
    }
}
 
int Solution::sumNumbers(TreeNode* A) {
    sum = 0;
    SumNumbersHelper(A, "");
    return sum;
}
