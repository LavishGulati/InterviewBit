#define pb push_back
#define all(x) x.begin(), x.end()

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    for(int j = 0; j < m; j++){
        dp[0][j] = A[0][j];
        for(int i = 1; i < n; i++){
            if(A[i][j] == 0) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j]+1;
        }
    }
    
    vector<int> helper;
    int MaxArea = 0;
    for(int i = 0; i < n; i++){
        helper.clear();
        for(int j = 0; j < m; j++){
            helper.pb(dp[i][j]);
        }
        sort(all(helper));
        for(int j = 0; j < m; j++){
            MaxArea = max(MaxArea, helper[j]*(m-j));
        }
    }
    
    return MaxArea;
}
