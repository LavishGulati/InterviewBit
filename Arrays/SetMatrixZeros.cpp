void Solution::setZeroes(vector<vector<int> > &A) {
    
    int m = A.size();
    int n = A[0].size();
    bool helper[m+n];
    for(int i = 0; i < m+n; i++){
        helper[i] = false;
    }
    for(int i = 0; i < m; i++){
        // if(helper[i]) continue;
        for(int j = 0; j < n; j++){
            // if(helper[m+j]) continue;
            if(A[i][j] == 0){
                helper[i] = true;
                helper[m+j] = true;
            }
        }
    }
    
    for(int i = 0; i < m+n; i++){
        if(helper[i]){
            if(i < m){
                for(int j = 0; j < n; j++) A[i][j] = 0;
            }
            else{
                for(int j = 0; j < m; j++) A[j][i-m] = 0;
            }
        }
    }
}

