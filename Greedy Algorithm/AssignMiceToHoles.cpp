#define all(x) x.begin(), x.end()

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(all(A));
    sort(all(B));
    int n = A.size();
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer = max(abs(A[i]-B[i]), answer);
    }
    return answer;
}
