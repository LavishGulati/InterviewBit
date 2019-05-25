int Solution::trailingZeroes(int A) {
    int NumTwo = 0;
    int n = A;
    int helper = 2;
    while(1){
        if(n/helper == 0) break;
        NumTwo += n/helper;
        helper *= 2;
    }
    
    int NumFive = 0;
    n = A;
    helper = 5;
    while(1){
        if(n/helper == 0) break;
        NumFive += n/helper;
        helper *= 5;
    }
    
    return min(NumTwo, NumFive);
}

