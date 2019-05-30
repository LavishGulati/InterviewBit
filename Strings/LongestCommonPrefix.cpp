string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    char c;
    for(int i = 0; ; i++){
        
        if(i >= A[0].length()) return A[0].substr(0, i);
        else c = A[0][i];
        
        for(int j = 1; j < n; j++){
            if(i >= A[j].length()) return A[0].substr(0, i);
            else if(A[j][i] != c) return A[0].substr(0, i);
        }
    }
}

