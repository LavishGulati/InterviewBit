bool IsAnagram(const string &A, const string &B, int s1, int s2, int l){
    int freq1[26];
    int freq2[26];
    for(int i = 0; i < 26; i++) freq1[i] = freq2[i] = 0;
    for(int i = s1; i < s1+l; i++){
        freq1[A[i]-'a']++;
    }
    for(int i = s2; i < s2+l; i++){
        freq2[B[i]-'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]) return false;
    }
    return true;
}

int Solution::isScramble(const string A, const string B) {
    int n = A.length();
    if(B.length() != n) return 0;
    
    if(!IsAnagram(A, B, 0, 0, n)) return 0;
    
    bool dp[n][n][n+1];
    for(int l = 0; l <= n; l++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j][l] = false;
                
                if(l == 0){
                    dp[i][j][l] = true;
                    continue;
                }
                
                if(l == 1 && A[i] == B[j]){
                    dp[i][j][l] = true;
                    continue;
                }
                
                if(n-i < l || n-j < l) continue;
                
                if(!IsAnagram(A, B, i, j, l)) continue;
                
                for(int k = 1; k < l; k++){
                    dp[i][j][l] = dp[i][j][k] && dp[i+k][j+k][l-k];
                    if(dp[i][j][l]) break;
                    dp[i][j][l] = dp[i][j+l-k][k] && dp[i+k][j][l-k];
                    if(dp[i][j][l]) break;
                }
                
            }
        }
    }
    
    return dp[0][0][n] ? 1 : 0;
}
