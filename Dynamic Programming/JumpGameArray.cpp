int Solution::canJump(vector<int> &A) {
    int n = A.size();
    
    int x = 0;
    for(int i = 0; i < n-1; i++){
        if(A[i] == 0 && x <= i){
            return 0;
        }
        
        x = max(x, A[i]+i);
    }
    
    return 1;
}
