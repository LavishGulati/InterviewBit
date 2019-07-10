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
 
vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode *temp = A, *prev = NULL, *cur;
    int si = INT_MIN, ei = INT_MAX;
    while(temp != NULL){
        if(temp->left == NULL){
            if(prev != NULL && temp != NULL && temp->val < prev->val){
                if(si == INT_MIN) si = prev->val;
                ei = temp->val;
            }
            
            prev = temp;
            
            temp = temp->right;
        }
        else{
            cur = temp->left;
            while(cur->right != NULL && cur->right != temp){
                cur = cur->right;
            }
            
            if(cur->right == NULL){
                cur->right = temp;
                temp = temp->left;
            }
            else{
                if(prev != NULL && temp != NULL){
                    if(temp->val < prev->val){
                        if(si == INT_MIN) si = prev->val;
                        ei = temp->val;
                    }
                }
                
                prev = temp;
                cur->right = NULL;
                temp = temp->right;
            }
        }
    }
    
    vector<int> output;
    output.pb(ei);
    output.pb(si);
    return output;
}
