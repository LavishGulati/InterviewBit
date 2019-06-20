#define pb push_back

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    int dp[n][n][8];
    
    // 0 - left
    for(int i = 0; i < n; i++){
        dp[i][0][0] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(A[i][j-1] == '1' && dp[i][j-1][0] == 0) dp[i][j][0] = dp[i][j-1][0]+1;
            else dp[i][j][0] = dp[i][j-1][0];
        }
    }
    
    // 1 - right
    for(int i = 0; i < n; i++){
        dp[i][n-1][1] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = n-2; j >= 0; j--){
            if(A[i][j+1] == '1' && dp[i][j+1][1] == 0) dp[i][j][1] = dp[i][j+1][1]+1;
            else dp[i][j][1] = dp[i][j+1][1];
        }
    }
    
    // 2 - up
    for(int j = 0; j < n; j++){
        dp[0][j][2] = 0;
    }
    for(int j = 0; j < n; j++){
        for(int i = 1; i < n; i++){
            if(A[i-1][j] == '1' && dp[i-1][j][2] == 0) dp[i][j][2] = dp[i-1][j][2]+1;
            else dp[i][j][2] = dp[i-1][j][2];
        }
    }
    
    // 3 - down
    for(int j = 0; j < n; j++){
        dp[n-1][j][3] = 0;
    }
    for(int j = 0; j < n; j++){
        for(int i = n-2; i >= 0; i--){
            if(A[i+1][j] == '1' && dp[i+1][j][3] == 0) dp[i][j][3] = dp[i+1][j][3]+1;
            else dp[i][j][3] = dp[i+1][j][3];
        }
    }
    
    // 4 - up left
    dp[0][0][4] = 0;
    for(int i = 1; i < n; i++) dp[i][0][4] = 0;
    for(int j = 1; j < n; j++) dp[0][j][4] = 0;
    for(int col = 1; col < n; col++){
        int i = 1, j = col;
        while(j < n){
            if(A[i-1][j-1] == '1' && dp[i-1][j-1][4] == 0) dp[i][j][4] = dp[i-1][j-1][4]+1;
            else dp[i][j][4] = dp[i-1][j-1][4];
            i++; j++;
        }
    }
    for(int row = 2; row < n; row++){
        int i = row, j = 1;
        while(i < n){
            if(A[i-1][j-1] == '1' && dp[i-1][j-1][4] == 0) dp[i][j][4] = dp[i-1][j-1][4]+1;
            else dp[i][j][4] = dp[i-1][j-1][4];
            i++; j++;
        }
    }
    
    // 5 - up right
    dp[0][n-1][5] = 0;
    for(int i = 1; i < n; i++) dp[i][n-1][5] = 0;
    for(int j = 0; j < n-1; j++) dp[0][j][5] = 0;
    for(int col = n-2; col >= 0; col--){
        int i = 1, j = col;
        while(j >= 0){
            if(A[i-1][j+1] == '1' && dp[i-1][j+1][5] == 0) dp[i][j][5] = dp[i-1][j+1][5]+1;
            else dp[i][j][5] = dp[i-1][j+1][5];
            i++; j--;
        }
    }
    for(int row = 2; row < n; row++){
        int i = row, j = n-2;
        while(i < n){
            if(A[i-1][j+1] == '1' && dp[i-1][j+1][5] == 0) dp[i][j][5] = dp[i-1][j+1][5]+1;
            else dp[i][j][5] = dp[i-1][j+1][5];
            i++; j--;
        }
    }
    
    // 6 - down left
    dp[n-1][0][6] = 0;
    for(int i = 0; i < n-1; i++) dp[i][0][6] = 0;
    for(int j = 1; j < n; j++) dp[n-1][j][6] = 0;
    for(int col = 1; col < n; col++){
        int i = n-2, j = col;
        while(j < n){
            if(A[i+1][j-1] == '1' && dp[i+1][j-1][6] == 0) dp[i][j][6] = dp[i+1][j-1][6]+1;
            else dp[i][j][6] = dp[i+1][j-1][6];
            i--; j++;
        }
    }
    for(int row = n-3; row >= 0; row--){
        int i = row, j = 1;
        while(i >= 0){
            if(A[i+1][j-1] == '1' && dp[i+1][j-1][6] == 0) dp[i][j][6] = dp[i+1][j-1][6]+1;
            else dp[i][j][6] = dp[i+1][j-1][6];
            i--; j++;
        }
    }
    
    // 7 - down right
    dp[n-1][n-1][7] = 0;
    for(int i = 0; i < n-1; i++) dp[i][n-1][7] = 0;
    for(int j = 0; j < n-1; j++) dp[n-1][j][7] = 0;
    for(int col = n-2; col >= 0; col--){
        int i = n-2, j = col;
        while(j >= 0){
            if(A[i+1][j+1] == '1' && dp[i+1][j+1][7] == 0) dp[i][j][7] = dp[i+1][j+1][7]+1;
            else dp[i][j][7] = dp[i+1][j+1][7];
            i--; j--;
        }
    }
    for(int row = n-3; row >= 0; row--){
        int i = row, j = n-2;
        while(i >= 0){
            if(A[i+1][j+1] == '1' && dp[i+1][j+1][7] == 0) dp[i][j][7] = dp[i+1][j+1][7]+1;
            else dp[i][j][7] = dp[i+1][j+1][7];
            i--; j--;
        }
    }
    
    
    vector< vector<int> > output;
    vector<int> v;
    int x;
    for(int i = 0; i < n; i++){
        v.clear();
        for(int j = 0; j < n; j++){
            x = 0;
            for(int k = 0; k < 8; k++){
                x += dp[i][j][k];
            }
            v.pb(x);
        }
        output.pb(v);
    }
    return output;
}
