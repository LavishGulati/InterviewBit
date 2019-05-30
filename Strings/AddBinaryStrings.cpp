string Solution::addBinary(string A, string B) {
    string output = "";
    bool IsCarry = false;
    
    int n = max(A.length(), B.length());
    int a = A.length(), b = B.length();
    for(int i = 0; i < n-a; i++) A = '0'+A;
    for(int i = 0; i < n-b; i++) B = '0'+B;
    
    for(int i = n-1; i >= 0; i--){
        if(A[i] == '0' && B[i] == '0'){
            if(IsCarry){
                output = '1'+output;
                IsCarry = false;
            }
            else output = '0'+output;
        }
        else if((A[i] == '0' && B[i] == '1') || (A[i] == '1' && B[i] == '0')){
            if(IsCarry) output = '0'+output;
            else output = '1'+output;
        }
        else{
            if(IsCarry) output = '1'+output;
            else{
                output = '0'+output;
                IsCarry = true;
            }
        }
    }
    
    if(IsCarry) output = '1'+output;
    
    return output;
}

