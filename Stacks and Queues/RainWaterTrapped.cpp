typedef long long ll;

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    
    ll answer = 0;
    int x = 0;
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(A[i] >= x){
            while(!st.empty()){
                answer += x-st.top();
                st.pop();
            }
            x = A[i];
            st.push(x);
        }
        else{
            st.push(A[i]);
        }
    }
    
    int m = st.size();
    while(!st.empty()) st.pop();
    x = 0;
    for(int i = n-1; i >= n-m; i--){
        if(A[i] >= x){
            while(!st.empty()){
                answer += x-st.top();
                st.pop();
            }
            x = A[i];
            st.push(x);
        }
        else{
            st.push(A[i]);
        }
    }
    
    return answer;
}
