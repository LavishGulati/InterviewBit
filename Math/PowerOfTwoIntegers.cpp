int Solution::isPower(int A) {
    if(A == 1) return 1;
    for(int i = 1; i <= sqrt(A); i++){
        for(int j = 2; j <= log2(A); j++){
            if(pow(i, j) == A) return 1;
        }
    }
    return 0;
}

