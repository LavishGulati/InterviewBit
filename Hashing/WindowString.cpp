bool check(int *A, int *B){
    for(int i = 0; i < 256; i++){
        if(A[i] < B[i]) return false;
    }
    return true;
}

string Solution::minWindow(string A, string B) {
    int n = A.length();
    int m = B.length();
    
    int *freq = new int[256];
    for(int i = 0; i < 256; i++) freq[i] = 0;
    for(int i = 0; i < m; i++) freq[B[i]]++;
    
    int *helper = new int[256];
    for(int i = 0; i < 256; i++) helper[i] = 0;
    
    int i = 0, j = 0;
    int MinLength = INT_MAX, si = -1, ei = -1;
    while(j < n){
        helper[A[j]]++;
        
        if(check(helper, freq)){
            if(j-i+1 < MinLength){
                MinLength = j-i+1;
                si = i;
                ei = j;
            }
            
            helper[A[i]]--;
            helper[A[j]]--;
            i++;
        }
        else{
            j++;
        }
    }
    
    if(si != -1) return A.substr(si, ei-si+1);
    else return "";
}
