int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int total = 0;
    int x = A[0];
    int y = B[0];
    int diagonal;
    for(int i = 1; i < A.size(); i++){
        // diagonal = min(A[i]-x, B[i]-y);
        // total += diagonal + max(A[i]-x, B[i]-y) - diagonal;
        total += max(abs(A[i]-x), abs(B[i]-y));
        x = A[i];
        y = B[i];
    }
    return total;
}
