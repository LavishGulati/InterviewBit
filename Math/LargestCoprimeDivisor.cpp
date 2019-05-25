int Solution::cpFact(int A, int B) {
    while(1){
        int gcd = __gcd(A, B);
        if(gcd == 1) break;
        A /= gcd;
    }
    
    return A;
}

