int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int answer = INT_MIN;
    int si = 0;
    int ei = n-1;
    while(si <= ei){
        answer = max(answer, (ei-si)*min(A[si], A[ei]));
        if(A[si] <= A[ei]) si++;
        else ei--;
    }
    return answer;
}
