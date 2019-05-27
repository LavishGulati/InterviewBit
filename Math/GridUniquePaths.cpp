typedef long long ll;

int Solution::uniquePaths(int A, int B) {
    if(A < B){
        int temp = A;
        A = B;
        B = temp;
    }
    
    ll factorial[B];
    factorial[0] = 1;
    factorial[1] = 1;
    for(ll i = 2; i < B; i++){
        factorial[i] = factorial[i-1]*i;
    }
    
    ll prod = 1;
    for(ll i = A; i <= A+B-2; i++){
        prod *= i;
    }
    
    return prod/factorial[B-1];
}

