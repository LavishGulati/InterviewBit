int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int row = -1;
    int si = 0, ei = n-1, mid;
    while(si <= ei){
        mid = (si+ei)/2;
        if(B > A[mid][0]){
            row = mid;
            si = mid+1;
        }
        else if(B < A[mid][0]){
            ei = mid-1;
        }
        else return 1;
    }
    
    if(row == -1) return 0;
    
    si = 0; ei = m-1;
    while(si <= ei){
        mid = (si+ei)/2;
        if(B > A[row][mid]) si = mid+1;
        else if(B < A[row][mid]) ei = mid-1;
        else return 1;
    }
    
    return 0;
}

