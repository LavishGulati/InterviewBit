#define pb push_back

int LargestRectangleHistogram(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> output;
    for(int i = 0; i < n; i++){
        while(!st.empty() && A[st.top()] >= A[i]){
            st.pop();
        }
        
        if(st.size() > 0){
            output.pb(st.top());
        }
        else{
            output.pb(-1);
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    int answer = INT_MIN;
    int i;
    for(i = 0; i < n; i++){
        while(!st.empty() && A[st.top()] > A[i]){
            if(output[st.top()] != -1) answer = max(answer, A[st.top()]*(i-output[st.top()]-1));
            else answer = max(answer, A[st.top()]*(i));
            
            st.pop();
        }
        
        st.push(i);
    }
    
    while(!st.empty()){
        if(output[st.top()] != -1) answer = max(answer, A[st.top()]*(i-output[st.top()]-1));
        else answer = max(answer, A[st.top()]*(i));
        
        st.pop();
    }
    
    return answer;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    for(int i = 0; i < n; i++){
        dp[i][0] = A[i][0];
        for(int j = 1; j < m; j++){
            if(A[i][j] == 1) dp[i][j] = dp[i][j-1]+1;
            else dp[i][j] = 0;
        }
    }
    
    vector<int> helper;
    int answer = 0, x;
    for(int j = 0; j < m; j++){
        helper.clear();
        for(int i = 0; i < n; i++){
            helper.pb(dp[i][j]);
        }
        x = LargestRectangleHistogram(helper);
        answer = max(answer, x);
    }
    return answer;
}
