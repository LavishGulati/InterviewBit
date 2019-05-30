int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    
    int partition = 1;
    int si = 0, ei = n-1, mid;
    
    while(si <= ei){
        mid = (si+ei)/2;
        if(A[mid] > A[si]){
            if(mid < n-1 && A[mid+1] < A[mid]){
                partition = mid;
                break;
            }
            else{
                si = mid+1;
            }
        }
        else{
            if(mid > 0 && A[mid-1] > A[mid]){
                partition = mid;
                break;
            }
            else ei = mid-1;
        }
    }
    
    si = partition, ei = n-1;
    while(si <= ei){
        mid = (si+ei)/2;
        if(A[mid] < B) si = mid+1;
        else if(A[mid] > B) ei = mid-1;
        else return mid;
    }
    
    si = 0; ei = partition-1;
    while(si <= ei){
        mid = (si+ei)/2;
        if(A[mid] < B) si = mid+1;
        else if(A[mid] > B) ei = mid-1;
        else return mid;
    }
    
    return -1;
}

