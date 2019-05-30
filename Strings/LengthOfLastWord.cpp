int Solution::lengthOfLastWord(const string A) {
    int n = A.length();
    int i = -1;
    int j = 0;
    int answer = 0;
    while(j < n){
        if(A[j] == ' ') j++;
        else{
            i = j;
            while(j < n && A[j] != ' ') j++;
            answer = j-i;
        }
    }
    return answer;
}

