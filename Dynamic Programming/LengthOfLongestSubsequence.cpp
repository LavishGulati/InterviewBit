typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return 0;
    
    int inc[n];
    inc[0] = 1;
    for(int i = 1; i < n; i++){
        inc[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                inc[i] = max(inc[i], inc[j]+1);
            }
        }
    }
    
    int dec[n];
    dec[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        dec[i] = 1;
        for(int j = i+1; j < n; j++){
            if(A[i] > A[j]){
                dec[i] = max(dec[i], dec[j]+1);
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; i++){
        answer = max(answer, inc[i]+dec[i]-1);
    }
    return answer;
}
