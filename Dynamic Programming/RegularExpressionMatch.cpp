int Solution::isMatch(const string A, const string B) {
    int n = A.length();
    int m = B.length();
    
    int output[m+1];
    int helper[m+1];
    
    output[m] = true;
    for(int j = m-1; j >= 0; j--){
        if(B[j] == '*'){
            output[j] = output[j+1];
        }
        else output[j] = false;
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int i = 0; i <= m; i++){
            helper[i] = output[i];
        }
        
        output[m] = false;
        for(int j = m-1; j >= 0; j--){
            if(B[j] == '*'){
                output[j] = helper[j] || output[j+1];
            }
            else if(B[j] == '?'){
                output[j] = helper[j+1];
            }
            else if(A[i] == B[j]){
                output[j] = helper[j+1];
            }
            else output[j] = false;
        }
    }
    
    return output[0] ? 1 : 0;
}
