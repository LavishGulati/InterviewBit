#define pb push_back

int answer;

int distance(int u, vector<int> **tree){
    int x, v;
    int helper[2] = {-1, -1};
    for(int i = 0; i < tree[u]->size(); i++){
        v = tree[u]->at(i);
        x = distance(v, tree);
        if(x > helper[1]){
            helper[0] = helper[1];
            helper[1] = x;
        }
        else if(x > helper[0]){
            helper[0] = x;
        }
    }
    
    answer = max(answer, helper[0]+helper[1]+2);
    return helper[1]+1;
}

int Solution::solve(vector<int> &A) {
    answer = 0;
    int n = A.size();
    if(n < 2) return 0;
    
    vector<int> **tree = new vector<int> *[n];
    for(int i = 0; i < n; i++){
        tree[i] = new vector<int>;
    }
    
    int src;
    for(int i = 0; i < n; i++){
        if(A[i] != -1){
            tree[A[i]]->pb(i);
        }
        else src = i;
    }
    
    distance(src, tree);
    return answer;
}
