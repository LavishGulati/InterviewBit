int Solution::diffPossible(const vector<int> &A, int B) {
    set<int> st;
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(st.find(A[i]-B) != st.end()) return 1;
        else if(st.find(B+A[i]) != st.end()) return 1;
        else st.insert(A[i]);
    }
    return 0;
}
