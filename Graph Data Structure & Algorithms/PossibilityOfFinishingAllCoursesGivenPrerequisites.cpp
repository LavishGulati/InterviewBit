#define pb push_back

bool dfs(int u, vector<int> **graph, bool *IsVisited, bool *InStack){
    IsVisited[u] = true;
    InStack[u] = true;
    
    int v;
    for(int i = 0; i < graph[u]->size(); i++){
        v = graph[u]->at(i);
        if(InStack[v]) return true;
        if(!IsVisited[v]){
            if(dfs(v, graph, IsVisited, InStack)) return true;
        }
    }
    
    InStack[u] = false;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<int> **graph = new vector<int> *[A];
    for(int i = 0; i < A; i++){
        graph[i] = new vector<int>;
    }
    
    for(int i = 0; i < B.size(); i++){
        graph[B[i]-1]->pb(C[i]-1);
    }
    
    bool *IsVisited = new bool[A];
    for(int i = 0; i < A; i++) IsVisited[i] = false;
    
    bool *InStack = new bool[A];
    for(int i = 0; i < A; i++) InStack[i] = false;
    
    for(int i = 0; i < A; i++){
        if(!IsVisited[i]){
            if(dfs(i, graph, IsVisited, InStack)) return 0;
        }
    }
    return 1;
}
