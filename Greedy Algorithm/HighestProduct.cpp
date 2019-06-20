#define all(x) x.begin(), x.end()

int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    sort(all(A));
    int answer = A[n-1]*A[n-2]*A[n-3];
    answer = max(answer, A[0]*A[1]*A[n-1]);
    return answer;
}
