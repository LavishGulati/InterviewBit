int Solution::colorful(int A) {
    string input = to_string(A);
    int n = input.length();
    set<int> st;
    int prod, i, j;
    for(i = 0; i < n; i++){
        prod = 1;
        for(j = i; j >= 0; j--){
            prod *= input[j]-'0';
        }
        
        j++;
        while(j <= i){
            if(st.find(prod) != st.end()) return 0;
            st.insert(prod);
            prod /= input[j]-'0';
            j++;
        }
    }
    
    return 1;
}
