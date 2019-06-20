/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode *> s1, s2;
    TreeNode *temp1, *temp2;
    temp1 = A;
    while(temp1 != NULL){
        s1.push(temp1);
        temp1 = temp1->left;
    }
    
    temp2 = A;
    while(temp2 != NULL){
        s2.push(temp2);
        temp2 = temp2->right;
    }
    
    temp1 = s1.top();
    temp2 = s2.top();
    while(temp1 != NULL && temp2 != NULL && temp1->val < temp2->val){
        if(temp1->val + temp2->val == B) return 1;
        else if(temp1->val + temp2->val < B){
            s1.pop();
            temp1 = temp1->right;
            while(temp1 != NULL){
                s1.push(temp1);
                temp1 = temp1->left;
            }
            temp1 = s1.top();
        }
        else{
            s2.pop();
            temp2 = temp2->left;
            while(temp2 != NULL){
                s2.push(temp2);
                temp2 = temp2->right;
            }
            temp2 = s2.top();
        }
    }
    
    return 0;
}
