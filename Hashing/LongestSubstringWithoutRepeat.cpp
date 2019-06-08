int Solution::lengthOfLongestSubstring(string A) {
    int n = A.length();
    
    set<char> st;
    int MaxLength = 0;
    int i = 0, j = 0;
    while(j < n){
        if(st.find(A[j]) == st.end()){
            st.insert(A[j]);
            j++;
        }
        else{
            MaxLength = max(MaxLength, j-i);
            while(A[i] != A[j]) i++;
            i++;
            j = i;
            st.clear();
        }
    }
    MaxLength = max(MaxLength, j-i);
    return MaxLength;
}
