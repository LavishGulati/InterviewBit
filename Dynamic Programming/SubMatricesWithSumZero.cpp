#define pb push_back

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0) return 0;
    int m = A[0].size();
    if(m == 0) return 0;
    
    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) dp[i][j] = A[i][j];
    }
    for(int j = 0; j < m; j++){
        for(int i = 1; i < n; i++) dp[i][j] += dp[i-1][j];
    }
    
    vector<int> helper;
    int num = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            helper.clear();
            for(int k = 0; k < m; k++){
                if(i == 0) helper.pb(dp[j][k]);
                else helper.pb(dp[j][k]-dp[i-1][k]);
            }
            for(int k = 1; k < m; k++){
                helper[k] += helper[k-1];
            }
            mp.clear();
            for(int k = 0; k < m; k++){
                if(helper[k] == 0) num++;
                if(mp.find(helper[k]) == mp.end()) mp[helper[k]] = 1;
                else{
                    num += mp[helper[k]];
                    mp[helper[k]]++;
                }
            }
        }
    }
    return num;
}
