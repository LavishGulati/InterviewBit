int overlap(string a, string b){
    int n = a.length();
    int m = b.length();
    for(int i = 0; i < n; i++){
        if(n-i >= m && a.substr(i, m) == b){
            return n;
        }
        else if(n-i < m && a.substr(i) == b.substr(0, n-i)){
            return i+m;
        }
    }
    
    return n+m;
}

int substring(int i, int mask, int **dp, int n, vector<string> &A, int **OverlapLength){
    if(dp[i][mask] != INT_MAX) return dp[i][mask];
    
    int num = 0;
    for(int j = 0; j < n; j++){
        if((mask&(1<<j)) != 0) num++;
    }
    
    if(num == 1){
        dp[i][mask] = A[i].length();
        return dp[i][mask];
    }
    
    int x, y;
    for(int j = 0; j < n; j++){
        if(j == i) continue;
        
        if((mask&(1<<j)) != 0){
            x = substring(j, mask^(1<<i), dp, n, A, OverlapLength);
            y = OverlapLength[j][i];
            y += x-A[j].length();
            if(y < dp[i][mask]){
                dp[i][mask] = y;
            }
        }
    }
    
    return dp[i][mask];
}

int Solution::solve(vector<string> &A) {
    int n = A.size();
    int **dp = new int *[n];
    for(int i = 0; i < n; i++){
        dp[i] = new int[1<<n];
        for(int j = 0; j < (1<<n); j++) dp[i][j] = INT_MAX;
    }
    
    int **OverlapLength = new int *[n];
    for(int i = 0; i < n; i++){
        OverlapLength[i] = new int[n];
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            OverlapLength[i][j] = overlap(A[i], A[j]);
        }
    }
    
    int mask = (1<<n)-1;
    for(int i = 0; i < n; i++){
        substring(i, mask, dp, n, A, OverlapLength);
    }
    
    int answer = INT_MAX;
    for(int i = 0; i < n; i++){
        answer = min(answer, dp[i][mask]);
    }
    return answer;
}
