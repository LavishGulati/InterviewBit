typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back

void BuildTree(int *tree, int si, int ei, int node){
    if(si == ei){
        tree[node] = 1;
        return;
    }
    
    int mid = (si+ei)/2;
    BuildTree(tree, si, mid, 2*node);
    BuildTree(tree, mid+1, ei, 2*node+1);
    
    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int *tree, int si, int ei, int node, int x){
    if(si == ei){
        return si;
    }
    
    int mid = (si+ei)/2;
    int left = tree[2*node];
    if(left >= x){
        return query(tree, si, mid, 2*node, x);
    }
    else{
        return query(tree, mid+1, ei, 2*node+1, x-left);
    }
}

void update(int *tree, int si, int ei, int node, int id){
    if(si == ei){
        tree[node] -= 1;
        return;
    }
    
    int mid = (si+ei)/2;
    if(id >= si && id <= mid){
        update(tree, si, mid, 2*node, id);
    }
    else{
        update(tree, mid+1, ei, 2*node+1, id);
    }
    
    tree[node] = tree[2*node]+tree[2*node+1];
}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    pii *input = new pii[n];
    for(int i = 0; i < n; i++){
        input[i] = mp(A[i], B[i]);
    }
    sort(input, input+n);
    
    vector<int> output(n);
    
    int *tree = new int[4*n];
    BuildTree(tree, 0, n-1, 1);
    
    int id;
    for(int i = 0; i < n; i++){
        id = query(tree, 0, n-1, 1, input[i].s+1);
        output[id] = input[i].f;
        update(tree, 0, n-1, 1, id);
    }
    return output;
}
