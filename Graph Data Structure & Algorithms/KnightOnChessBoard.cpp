int NextX[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int NextY[8] = {2, 1, -1, -2, -2, -1, 1, 2};

class cell{
public:
    int row, col, h;
    
    cell(){
        
    }
    
    cell(int r, int c, int h){
        this->row = r;
        this->col = c;
        this->h = h;
    }
};

int bfs(int n, int m, int x, int y, int a, int b, bool **IsVisited){
    queue<cell> q;
    q.push(cell(x, y, 0));
    IsVisited[x][y] = true;
    
    int u, v, h;
    while(!q.empty()){
        x = q.front().row;
        y = q.front().col;
        h = q.front().h;
        if(x == a && y == b){
            return h;
        }
        q.pop();
        
        
        for(int i = 0; i < 8; i++){
            u = x+NextX[i];
            v = y+NextY[i];
            if(u >= 0 && u < n && v >= 0 && v < m){
                if(!IsVisited[u][v]){
                    q.push(cell(u, v, h+1));
                    IsVisited[u][v] = true;
                }
            }
        }
    }
    
    return -1;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    bool **IsVisited = new bool *[A];
    for(int i = 0; i < A; i++){
        IsVisited[i] = new bool[B];
        for(int j = 0; j < B; j++) IsVisited[i][j] = false;
    }
    
    return bfs(A, B, C-1, D-1, E-1, F-1, IsVisited);
}
