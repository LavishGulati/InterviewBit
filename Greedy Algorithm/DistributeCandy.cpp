#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
#define f first
#define s second
#define all(x) x.begin(), x.end()

int Solution::candy(vector<int> &A) {
    int n = A.size();

    int dp[n];
    for(int i = 0; i < n; i++) dp[i] = 1;
    
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1]) dp[i] = dp[i-1]+1;
    }
    for(int i = n-2; i >= 0; i--){
        if(A[i] > A[i+1]) dp[i] = max(dp[i], dp[i+1]+1);
    }
    
    int total = 0;
    for(int i = 0; i < n; i++){
        total += dp[i];
    }
    return total;
}
