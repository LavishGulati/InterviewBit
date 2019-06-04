#define pb push_back

int Solution::largestRectangleArea(vector<int> &A) {
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
