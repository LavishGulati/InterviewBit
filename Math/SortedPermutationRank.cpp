#define MOD 1000003

int Solution::findRank(string A) {
    int n = A.length();
    
    int factorial[n];
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i < n; i++){
        factorial[i] = (i*factorial[i-1])%MOD;
    }
    
    char SmallestChar = 'z';
    for(int i = 0; i < n; i++){
        if(A[i] < SmallestChar) SmallestChar = A[i];
    }
    
    int total = 0;
    for(int i = 0; i < n; i++){
        int num = 0;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[i]) num++;
        }
        total = (total+((num)*factorial[n-i-1])%MOD)%MOD;
    }
    return total+1;
}

