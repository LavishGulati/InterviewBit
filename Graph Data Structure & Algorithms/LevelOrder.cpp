/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define mp make_pair
#define f first
#define s second
#define pb push_back

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue< pair<TreeNode *, int> > q;
    vector<int> helper;
    vector<vector<int> > output;
    
    int h;
    q.push(mp(A, 0));
    while(!q.empty()){
        helper.clear();
        h = q.front().s;
        while(!q.empty() && q.front().s == h){
            if(q.front().f->left != NULL){
                q.push(mp(q.front().f->left, h+1));
            }
            if(q.front().f->right != NULL){
                q.push(mp(q.front().f->right, h+1));
            }
            helper.pb(q.front().f->val);
            q.pop();
        }
        output.pb(helper);
    }
    return output;
}
