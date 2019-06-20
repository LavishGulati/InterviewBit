/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *BuildTreeHelper(vector<int> &A, int ai, int aj, vector<int> &B, int bi, int bj){
    if(ai > aj) return NULL;
    else if(ai == aj){
        TreeNode *NewNode = new TreeNode(A[ai]);
        return NewNode;
    }
    
    TreeNode *NewNode = new TreeNode(B[bj]);
    int mid = ai;
    while(mid <= aj){
        if(A[mid] == NewNode->val) break;
        mid++;
    }
    
    TreeNode *LeftChild, *RightChild;
    LeftChild = BuildTreeHelper(A, ai, mid-1, B, bi, bi+mid-1-ai);
    RightChild = BuildTreeHelper(A, mid+1, aj, B, bi+mid-ai, bj-1);
    NewNode->left = LeftChild;
    NewNode->right = RightChild;
    return NewNode;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return BuildTreeHelper(A, 0, A.size()-1, B, 0, B.size()-1);
}
