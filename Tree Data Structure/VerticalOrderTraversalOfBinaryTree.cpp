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
#define f first
#define s second
typedef pair<int, int> pii;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector< vector<pii> > output;
map<int, int> m;
queue<TreeNode *> q;
 
void VOT(TreeNode *root, int x, int h){
    if(root == NULL) return;
   
    if(m.find(x) == m.end()){
        vector<pii> helper;
        helper.pb(mp(h, root->val));
        m[x] = output.size();
        output.pb(helper);
    }
    else{
        output[m[x]].pb(mp(h, root->val));
    }
    
    VOT(root->left, x-1, h+1);
    VOT(root->right, x+1, h+1);
}

bool compare(pii a, pii b){
    return a.f < b.f;
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    while(!q.empty()) q.pop();
    
    output.clear();
    m.clear();
    VOT(A, 0, 0);
    
    for(int i = 0; i < output.size(); i++){
        stable_sort(all(output[i]), compare);
    }
    
    vector< vector<int> > SortedOutput;
    for(auto i = m.begin(); i != m.end(); i++){
        vector<int> helper;
        for(int j = 0; j < output[i->s].size(); j++){
            helper.pb(output[i->s][j].s);
        }
        SortedOutput.pb(helper);
    }
    return SortedOutput;
}
