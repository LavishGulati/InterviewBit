/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &A) {
    TreeNode *root, *NewNode, *temp, *parent;
    stack<TreeNode *> s;
    for(int i = 0; i < A.size(); i++){
        if(s.empty()){
            NewNode = new TreeNode(A[i]);
            s.push(NewNode);
            continue;
        }
        
        while(s.size() > 1 && A[i] > s.top()->val){
            temp = s.top();
            s.pop();
            parent = s.top();
            if(A[i] < parent->val){
                s.push(temp);
                break;
            }
            s.pop();
            parent->right = temp;
            s.push(parent);
        }
        
        if(A[i] > s.top()->val){
            temp = s.top();
            s.pop();
            parent = new TreeNode(A[i]);
            parent->left = temp;
            s.push(parent);
        }
        else{
            NewNode = new TreeNode(A[i]);
            s.push(NewNode);
        }
    }
    
    while(s.size() > 1){
        temp = s.top();
        s.pop();
        parent = s.top();
        s.pop();
        parent->right = temp;
        s.push(parent);
    }
    
    return s.top();
}
