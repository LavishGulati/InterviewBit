/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode *> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while(!s.empty()) s.pop();
    TreeNode *temp = root;
    while(temp != NULL){
        s.push(temp);
        temp = temp->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return s.size() > 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *temp = s.top();
    int answer = temp->val;
    s.pop();
    temp = temp->right;
    while(temp != NULL){
        s.push(temp);
        temp = temp->left;
    }
    return answer;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
