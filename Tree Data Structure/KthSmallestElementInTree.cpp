/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

map<TreeNode *, int> m; 

int CountLeftNodes(TreeNode *A){
    if(A == NULL){
        return 0;
    }
    
    int LeftNodes, RightNodes;
    LeftNodes = CountLeftNodes(A->left);
    RightNodes = CountLeftNodes(A->right);
    m[A] = LeftNodes+1;
    return LeftNodes+RightNodes+1;
}

int KthSmallestHelper(TreeNode *A, int B){
    int LeftNodes = m[A];
    
    if(B == LeftNodes) return A->val;
    else if(B < LeftNodes){
        return KthSmallestHelper(A->left, B);
    }
    else{
        return KthSmallestHelper(A->right, B-LeftNodes);
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    m.clear();
    CountLeftNodes(A);
    return KthSmallestHelper(A, B);
}
