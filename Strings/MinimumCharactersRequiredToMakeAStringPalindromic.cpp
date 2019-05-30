#define all(x) x.begin(), x.end()

int Solution::solve(string A) {
    int n = A.length();
    string helper = A;
    reverse(all(helper));
    helper = A+'0'+helper;
    
    int lps[2*n+1];
    lps[0] = 0;
    int len = 0;
    for(int i = 1; i < 2*n+1; i++){
        if(helper[i] == helper[len]){
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
    
    return n-lps[2*n];
}

