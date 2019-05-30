int Solution::romanToInt(string A) {
    int n = A.length();
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == 'I'){
            if(i < n-1 && (A[i+1] == 'V' || A[i+1] == 'X')) answer -= 1;
            else answer += 1;
        }
        else if(A[i] == 'V'){
            answer += 5;
        }
        else if(A[i] == 'X'){
            if(i < n-1 && (A[i+1] == 'L' || A[i+1] == 'C')) answer -= 10;
            else answer += 10;
        }
        else if(A[i] == 'L'){
            answer += 50;
        }
        else if(A[i] == 'C'){
            if(i < n-1 && (A[i+1] == 'M' || A[i+1] == 'D')) answer -= 100;
            else answer += 100;
        }
        else if(A[i] == 'D'){
            answer += 500;
        }
        else if(A[i] == 'M'){
            answer += 1000;
        }
    }
    
    return answer;
}
