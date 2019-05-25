string Solution::convertToTitle(int A) {
    string output = "";
    while(A > 0){
        int x = (A-1)%26;
        char c = 'A'+x;
        output = c+output;
        A = (A-1)/26;
    }
    return output;
}

