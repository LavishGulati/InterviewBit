int Solution::isPalindrome(string A) {
    string input = "";
    for(int i = 0; i < A.length(); i++){
        if(A[i] >= 'a' && A[i] <= 'z') input += A[i];
        if(A[i] >= '0' && A[i] <= '9') input += A[i];
        if(A[i] >= 'A' && A[i] <= 'Z') input += (A[i]+32);
    }
    
    for(int i = 0; i <= input.length()/2; i++){
        if(input[i] != input[input.length()-i-1]) return 0;
    }
    
    return 1;
}

