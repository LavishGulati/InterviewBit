int Solution::titleToNumber(string A) {
    int n = A.length();
    int total = 0;
    int helper = 1;
    for(int i = n-1; i >= 0; i--){
        int x = A[i]-'A'+1;
        total += helper*x;
        helper *= 26;
    }
    return total;
}

