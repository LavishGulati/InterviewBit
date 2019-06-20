typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int prim(vector<pii> **graph, int n){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    
    int key[n];
    for(int i = 0; i < n; i++) key[i] = INT_MAX;
    
    bool InMST[n];
    for(int i = 0; i < n; i++) InMST[i] = false; 
    
    pq.push(mp(0, 0));
    key[0] = 0;
    
    int u, v, w;
    pii x;
    while(!pq.empty()){
        u = pq.top().s;
        pq.pop();
        InMST[u] = true;
        
        for(int i = 0; i < graph[u]->size(); i++){
            x = graph[u]->at(i);
            v = x.f;
            w = x.s;
            if(!InMST[v] && key[v] > w){
                key[v] = w;
                pq.push(mp(w, v));
            }
        }
    }
    
    int total = 0;
    for(int i = 0; i < n; i++) total += key[i];
    return total;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<pii> **graph = new vector<pii> *[A];
    for(int i = 0; i < A; i++){
        graph[i] = new vector<pii>;
    }
    
    for(int i = 0; i < B.size(); i++){
        graph[B[i][0]-1]->pb(mp(B[i][1]-1, B[i][2]));
        graph[B[i][1]-1]->pb(mp(B[i][0]-1, B[i][2]));
    }
    
    return prim(graph, A);
}
