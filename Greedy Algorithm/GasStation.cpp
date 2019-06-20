int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    
    int j = 0, i = 0;
    int sum;
    while(j < n){
        sum = 0;
        if(A[i%n]-B[i%n] < 0){
            i++;
            j = i;
            continue;
        }
        else{
            sum = A[i%n]-B[i%n];
            i++;
        }
        
        while(1){
            if(i%n == j) return j;
            if(sum+A[i%n]-B[i%n] < 0){
                i++;
                j = i;
                break;
            }
            else{
                sum += A[i%n]-B[i%n];
                i++;
            }
        }
        
    }
    
    return -1;
}
