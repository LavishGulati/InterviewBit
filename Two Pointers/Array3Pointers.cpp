int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int answer = INT_MAX, x;
    while(i < A.size() && j < B.size() && k < C.size()){
        answer = min(answer, max(abs(A[i]-B[j]), max(abs(B[j]-C[k]), abs(A[i]-C[k]))));
        x = min(A[i], min(B[j], C[k]));
        if(x == A[i]) i++;
        else if(x == B[j]) j++;
        else k++;
    }
    return answer;
}
