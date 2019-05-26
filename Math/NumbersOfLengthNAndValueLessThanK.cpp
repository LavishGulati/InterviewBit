int Solution::solve(vector<int> &A, int B, int C) {
    int n = A.size();
    if(n == 0) return 0;
    
    int IsPresent[10];
    for(int i = 0; i < 10; i++) IsPresent[i] = false;
    for(int i = 0; i < n; i++) IsPresent[A[i]] = true;
    
    int m[10];
    int i = 0;
    for(; i < n; i++){
        int start = (i == 0) ? 0 : A[i-1]+1;
        for(int j = start; j <= A[i]; j++){
            m[j] = i;
        }
    }
    for(int j = A[n-1]+1; j < 10; j++) m[j] = i;
    
    string sc = to_string(C);
    
    int power[sc.length()+1];
    power[0] = 1;
    power[1] = n;
    for(int i = 2; i < sc.length()+1; i++) power[i] = power[i-1]*n;
    
    bool IsZero = (A[0] == 0) ? true : false;
    
    if(B < sc.length()){
        if(!IsZero || B == 1) return pow(n, B);
        else return (n-1)*pow(n, B-1);
    }
    else if(B > sc.length()) return 0;
    
    
    
    int total = 0;
    
    if(B == 1) return m[sc[0]-'0'];
    
    for(int i = 0; i < B; i++){
        int x = sc[i]-'0';
        if(i == 0){
            if(IsZero){
                int y = (m[x]-1)*power[sc.length()-i-1];
                total += y;
            }
            else{
                int y = m[x]*power[sc.length()-i-1];
                total += y;
            }
        }
        else{
            int y = m[x]*power[sc.length()-i-1];
            total += y;
        }
        if(!IsPresent[x]) break;
    }
    
    return total;
}

