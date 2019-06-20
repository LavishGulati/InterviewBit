int NextX[4] = {0, 1, -1, 0};
int NextY[4] = {1, 0, 0, -1};

void dfs(int x, int y, vector<string> &A, bool **IsVisited){
    IsVisited[x][y] = true;
    
    int u, v;
    for(int i = 0; i < 4; i++){
        u = x+NextX[i];
        v = y+NextY[i];
        if(u >= 0 && u < A.size() && v >= 0 && v < A[0].size() && A[u][v] == 'X' && !IsVisited[u][v]){
            dfs(u, v, A, IsVisited);
        }
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    if(n == 0 || m == 0) return 0;
    
    bool **IsVisited = new bool *[n];
    for(int i = 0; i < n; i++){
        IsVisited[i] = new bool[m];
        for(int j = 0; j < m; j++) IsVisited[i][j] = false;
    }
    
    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'X' && !IsVisited[i][j]){
                total++;
                dfs(i, j, A, IsVisited);
            }
        }
    }
    return total;
}
