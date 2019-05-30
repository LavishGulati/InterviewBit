int Solution::searchInsert(vector<int> &A, int B) {
    int n = A.size();
    int si = 0, ei = n-1, mid;
    while(si <= ei){
        mid = (si+ei)/2;
        if(B > A[mid]) si = mid+1;
        else if(B < A[mid]) ei = mid-1;
        else break;
    }
    
    if(A[mid] == B) return mid;
    else if(A[mid] < B) return mid+1;
    else if(A[mid] > B) return mid;
}

