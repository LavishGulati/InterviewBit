int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    vector<int> CumSum = A;
    for(int i = 1; i < A.size(); i++){
        CumSum[i] += CumSum[i-1];
    }
    
    int total = 0, MaxSum = INT_MIN;
    int MaxNumber = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        MaxNumber = max(MaxNumber, A[i]);
    }
    
    if(MaxNumber <= 0){
        return MaxNumber;
    }
    
    int i = 0, j = 0;
    while(i < n && j < n){
        if(i == 0) total = CumSum[j];
        else total = CumSum[j]-CumSum[i-1];
        
        MaxSum = max(MaxSum, total);
        
        j++;
        
        if(total <= 0){
            i = j;
        }
    }
    
    return MaxSum;
}

