int Solution::jump(vector<int> &A) {
    int n = A.size();
    
    if(n == 1) return 0;
    if(A[0] == 0) return -1;
    
    int si = 1, ei = A[0];
    int num = 1, x;
    while(ei < n-1){
        x = 0;
        for(int i = si; i <= ei; i++){
            x = max(x, i+A[i]);
        }
        
        if(x <= ei) return 0;
        si = ei+1;
        ei = x;
        num++;
    }
    
    return num;
}
