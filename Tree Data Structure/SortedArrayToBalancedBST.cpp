/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *SortedArrayToBSTHelper(const vector<int> &A, int si, int ei){
    if(si > ei) return NULL;
    else if(si == ei){
        TreeNode *NewNode = new TreeNode(A[si]);
        return NewNode;
    }
    
    int mid = (si+ei)/2;
    TreeNode *NewNode = new TreeNode(A[mid]);
    TreeNode *LeftChild, *RightChild;
    LeftChild = SortedArrayToBSTHelper(A, si, mid-1);
    RightChild = SortedArrayToBSTHelper(A, mid+1, ei);
    NewNode->left = LeftChild;
    NewNode->right = RightChild;
    return NewNode;
} 

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return SortedArrayToBSTHelper(A, 0, A.size()-1);
}
