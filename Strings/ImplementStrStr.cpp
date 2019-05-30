int Solution::strStr(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    
    if(n == 0 || m == 0 || m > n) return -1;
    int lps[m];
    lps[0] = 0;
    int len = 0;
    for(int i = 1; i < m; i++){
        if(B[i] == B[len]){
            len++;
            lps[i] = len;
        }
        else{
            if(len == 0){
                lps[i] = 0;
            }
            else{
                len = lps[len-1];
                i--;
            }
        }
    }
    
    int i = 0, j = 0;
    while(i < n){
        if(A[i] == B[j]){
            i++;
            j++;
            if(j == m) return i-m;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else i++;
        }
    }
    
    return -1;
}

