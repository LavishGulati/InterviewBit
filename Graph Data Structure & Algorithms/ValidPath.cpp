double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
}

int NextX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int NextY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dfs(int row, int col, int A, int B, bool **graph, bool **IsVisited){
    IsVisited[row][col] = true;
    if(row == A && col == B) return true;
    
    int u, v;
    for(int i = 0; i < 8; i++){
        u = row+NextX[i];
        v = col+NextY[i];
        if(u >= 0 && u <= A && v >= 0 && v <= B && graph[u][v] && !IsVisited[u][v]){
            if(dfs(u, v, A, B, graph, IsVisited)) return true;
        }
    }
    
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    bool **graph = new bool *[A+1];
    for(int i = 0; i <= A; i++){
        graph[i] = new bool[B+1];
        for(int j = 0; j <= B; j++){
            graph[i][j] = true;
            for(int k = 0; k < C; k++){
                if(distance(i, j, E[k], F[k]) <= D){
                    graph[i][j] = false;
                    break;
                }
            }
        }
    }
    
    bool **IsVisited = new bool *[A+1];
    for(int i = 0; i <= A; i++){
        IsVisited[i] = new bool[B+1];
        for(int j = 0; j <= B; j++) IsVisited[i][j] = false;
    }
    if(dfs(0, 0, A, B, graph, IsVisited)) return "YES";
    else return "NO";
}
