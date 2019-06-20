#define pb push_back
typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

int change(string &a, string &b){
    int n = a.length();
    int num = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) num++;
    }
    return num;
}

int bfs(int u, int n, vector<int> **graph, bool *IsVisited){
    queue<pii> q;
    q.push(mp(n-1, 1));
    IsVisited[n-1] = true;
    
    int cur, v, h;
    while(!q.empty()){
        cur = q.front().f;
        h = q.front().s;
        if(cur == u) return h;
        q.pop();
        
        for(int i = 0; i < graph[cur]->size(); i++){
            v = graph[cur]->at(i);
            if(!IsVisited[v]){
                q.push(mp(v, h+1));
                IsVisited[v] = true;
            }
        }
    }
    return 0;
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    if(start == end) return 1;
    
    dictV.pb(start);
    dictV.pb(end);
    int n = dictV.size();
    
    vector<int> **graph = new vector<int> *[n];
    for(int i = 0; i < n; i++){
        graph[i] = new vector<int>;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(change(dictV[i], dictV[j]) == 1){
                graph[i]->pb(j);
                graph[j]->pb(i);
            }
        }
    }
    
    bool *IsVisited = new bool[n];
    for(int i = 0; i < n; i++) IsVisited[i] = false;
    return bfs(n-2, n, graph, IsVisited);
}
