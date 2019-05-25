int gcd2(int a, int b){
    if(b == 1 || a == 1) return 1;
    if(b == 0) return a;
    if(a == 0) return b;
    
    return gcd2(b, a%b);
}

int Solution::gcd(int A, int B) {
    if(A > B) return gcd2(A, B);
    else return gcd2(B, A);
}
