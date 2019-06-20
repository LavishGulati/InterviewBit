int Solution::wordBreak(string A, vector<string> &B) {
    set<string> helper[26];
    for(int i = 0; i < B.size(); i++){
        helper[B[i][0]-'a'].insert(B[i]);
    }
    
    int n = A.length();
    bool dp[n];
    string s;
    for(int i = n-1; i >= 0; i--){
        dp[i] = false;
        if(helper[A[i]-'a'].find(A.substr(i)) != helper[A[i]-'a'].end()){
            dp[i] = true;
            continue;
        }
        
        s = "";
        for(int j = 1; j < n-i; j++){
            s += A[i+j-1];
            if(helper[A[i]-'a'].find(s) != helper[A[i]-'a'].end()){
                dp[i] = dp[i+j];
            }
            if(dp[i]) break;
        }
    }
    
    return dp[0] ? 1 : 0;
}
