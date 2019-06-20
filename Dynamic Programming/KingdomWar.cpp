int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int cum[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cum[i][j] = A[i][j];
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            cum[i][j] += cum[i][j-1];
        }
    }
    
    for(int j = 0; j < m; j++){
        for(int i = 1; i < n; i++){
            cum[i][j] += cum[i-1][j];
        }
    }
    
    int answer = INT_MIN, x;
    for(int i = n-1; i >= 0; i--){
        int j = 0;
        while(j < m){
            if(i == 0){
                if(j > 0) x = cum[n-1][j]-cum[n-1][j-1];
                else x = cum[n-1][j];
            }
            else{
                if(j > 0) x = cum[n-1][j]-cum[i-1][j]-cum[n-1][j-1]+cum[i-1][j-1];
                else x = cum[n-1][j]-cum[i-1][j];
            }
            if(x >= 0) break;
            j++;
        }
        if(i == 0){
            x = cum[n-1][m-1];
            if(j == m){
                if(m-2 >= 0) x -= cum[n-1][m-2];
            }
            else if(j > 0) x -= cum[n-1][j-1];
        }
        else{
            x = cum[n-1][m-1]-cum[i-1][m-1];
            if(j == m){
                if(m-2 >= 0) x -= cum[n-1][m-2]-cum[i-1][m-2];
            }
            else if(j > 0) x -= cum[n-1][j-1]-cum[i-1][j-1];
        }
        answer = max(answer, x);
    }
    
    return answer;
}
