int NextX[4] = {1, 0, -1, 0};
int NextY[4] = {0, 1, 0, -1};

bool dfs(int x, int y, vector<string> &A, int id, string &B){
    if(id == B.length()) return true;
    
    int u, v;
    for(int i = 0; i < 4; i++){
        u = x+NextX[i];
        v = y+NextY[i];
        if(u >= 0 & u < A.size() && v >= 0 && v < A[0].size()){
            if(A[u][v] == B[id]){
                if(dfs(u, v, A, id+1, B)) return true;
            }
        }
    }
    
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    if(m == 0) return 0;
    
    if(B.length() == 0) return 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == B[0]){
                if(dfs(i, j, A, 1, B)) return 1;
            }
        }
    }
    
    return 0;
}
