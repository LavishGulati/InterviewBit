#define pb push_back

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> output;
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= A[i]){
            st.pop();
        }
        
        if(st.size() > 0){
            output.pb(st.top());
        }
        else{
            output.pb(-1);
        }
        st.push(A[i]);
    }
    
    return output;
}
