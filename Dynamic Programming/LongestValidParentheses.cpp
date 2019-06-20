int Solution::longestValidParentheses(string A) {
    int n = A.length();
    if(n == 0) return 0;
    
    int dp[n];
    stack<char> s;
    
    dp[0] = 0;
    if(A[0] == '(') s.push('(');
    
    int x;
    for(int i = 1; i < n; i++){
        dp[i] = 0;
        if(A[i] == '('){
            s.push('(');
        }
        else{
            x = dp[i-1];
            if(s.size() > 0){
                if(i-dp[i-1]-2 >= 0) dp[i] = dp[i-1]+dp[i-dp[i-1]-2]+2;
                else dp[i] = dp[i-1]+2;
                s.pop();
            }
        }
    }
    
    int MaxLength = 0;
    for(int i = 0; i < n; i++) MaxLength = max(MaxLength, dp[i]);
    return MaxLength;
}
