int NextX[4] = {1, 0, -1, 0};
int NextY[4] = {0, 1, 0, -1};

bool region(int x, int y, vector<vector<char> > &A, bool **IsVisited){
    IsVisited[x][y] = true;
    
    int u, v;
    bool ans = true;
    for(int i = 0; i < 4; i++){
        u = x+NextX[i];
        v = y+NextY[i];
        if(u >= 0 && u < A.size() && v >= 0 && v < A[0].size()){
            if(A[u][v] == 'O' && !IsVisited[u][v]){
                if(!region(u, v, A, IsVisited)){
                    ans = false;
                }
            }
        }
        else ans = false;
    }
    
    return ans;
}

void change(int x, int y, vector<vector<char> > &A){
    A[x][y] = 'X';
    
    int u, v;
    for(int i = 0; i < 4; i++){
        u = x+NextX[i];
        v = y+NextY[i];
        if(u >= 0 && u < A.size() && v >= 0 && v < A[0].size()){
            if(A[u][v] == 'O'){
                change(u, v, A);
            }
        }
    }
}

void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    if(n == 0) return;
    int m = A[0].size();
    if(m == 0) return;
    
    bool **IsVisited = new bool *[n];
    for(int i = 0; i < n; i++){
        IsVisited[i] = new bool[m];
        for(int j = 0; j < m; j++) IsVisited[i][j] = false;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'O' && !IsVisited[i][j]){
                if(region(i, j, A, IsVisited)){
                    change(i, j, A);
                }
            }
        }
    }
}
