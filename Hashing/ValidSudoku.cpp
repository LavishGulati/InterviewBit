bool IsValid(const vector<string> &A, int row, int col){
    for(int i = 0; i < 9; i++){
        if(i == row) continue;
        else if(A[i][col] == A[row][col]) return false;
    }
    
    for(int j = 0; j < 9; j++){
        if(j == col) continue;
        else if(A[row][j] == A[row][col]) return false;
    }
    
    for(int i = (row/3)*3; i < (row/3 + 1)*3; i++){
        for(int j = (col/3)*3; j < (col/3 + 1)*3; j++){
            if(i == row && j == col) continue;
            else if(A[i][j] == A[row][col]) return false;
        }
    }
    
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(A[i][j] != '.' && !IsValid(A, i, j)){
                return 0;
            }
        }
    }
    
    return 1;
}
