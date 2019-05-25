int Solution::isPalindrome(int A) {
    if(A < 0) return 0;
    int n = A;
    int d = 0;
    while(n > 0){
        d++;
        n /= 10;
    }
    
    d--;
    n = A;
    while(d > 0){
        if(n%10 != (int(n/pow(10, d)))%10) return 0;
        n /= 10;
        d -= 2;
    }
    return 1;
}

