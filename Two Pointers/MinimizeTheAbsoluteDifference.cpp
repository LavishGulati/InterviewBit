int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int answer = INT_MAX;
    int i = 0, j = 0, k = 0;
    while(i < A.size() && j < B.size() && k < C.size()){
        answer = min(answer, abs(max(A[i], max(B[j], C[k]))-min(A[i], min(B[j], C[k]))));
        
        if(min(A[i], min(B[j], C[k])) == A[i]) i++;
        else if(min(A[i], min(B[j], C[k])) == B[j]) j++;
        else k++;
    }
    return answer;
}
