bool IsSafe(int row, int col, vector<vector<char> > &A, int x){
    for(int i = 0; i < 9; i++){
        if(i == row || A[i][col] == '.') continue;
        
        if(A[i][col] == x+'0') return false;
    }
    
    for(int j = 0; j < 9; j++){
        if(j == col || A[row][j] == '.') continue;
        
        if(A[row][j] == x+'0') return false;
    }
    
    for(int i = (row/3)*3; i < (row/3 + 1)*3; i++){
        for(int j = (col/3)*3; j < (col/3 + 1)*3; j++){
            if(A[i][j] == '.') continue;
            
            if(A[i][j] == x+'0') return false;
        }
    }
    
    return true;
}

bool SolveSudokuHelper(int row, int col, vector<vector<char> > &A, vector<vector<char> > &helper){
    if(row == 9) return true;
    
    if(helper[row][col] != '.'){
        if(col == 8){
            if(SolveSudokuHelper(row+1, 0, A, helper)) return true;
        }
        else{
            if(SolveSudokuHelper(row, col+1, A, helper)) return true;
        }
        
        return false;
    }
    
    for(int i = 1; i <= 9; i++){
        if(IsSafe(row, col, A, i)){
            A[row][col] = '0'+i;
            if(col == 8){
                if(SolveSudokuHelper(row+1, 0, A, helper)) return true;
            }
            else{
                if(SolveSudokuHelper(row, col+1, A, helper)) return true;
            }
            A[row][col] = '.';
        }
    }
    
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    vector< vector<char> > helper = A;
    SolveSudokuHelper(0, 0, A, helper);
}
