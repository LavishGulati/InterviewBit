void Solution::reverseWords(string &A) {
    int n = A.length();
    int i = 0, j = 0;
    string answer = "";
    while(j < n){
        if(A[j] == ' ') j++;
        else{
            i = j;
            while(j < n && A[j] != ' ') j++;
            answer = " "+A.substr(i, j-i)+answer;
        }
    }
    if(answer[0] == ' ') answer = answer.substr(1);
    A = answer;
}

