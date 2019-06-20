/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
 
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue< pair<TreeNode *, int> > q;
    vector< vector<int> > output;
    vector<int> helper;
    
    q.push(mp(A, 0));
    TreeNode *temp;
    int h;
    while(!q.empty()){
        h = q.front().s;
        helper.clear();
        while(!q.empty() && q.front().s == h){
            temp = q.front().f;
            q.pop();
            if(temp->left != NULL) q.push(mp(temp->left, h+1));
            if(temp->right != NULL) q.push(mp(temp->right, h+1));
            helper.pb(temp->val);
        }
        
        if(h%2 == 0) output.pb(helper);
        else{
            reverse(all(helper));
            output.pb(helper);
        }
    }
    
    return output;
}
