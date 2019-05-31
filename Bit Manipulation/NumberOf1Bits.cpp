int Solution::numSetBits(unsigned int A) {
    int num = 0;
    while(A > 0){
        if(A%2 == 1) num++;
        A /= 2;
    }
    return num;
}

