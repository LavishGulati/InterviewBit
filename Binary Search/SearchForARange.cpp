#define pb push_back

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n = A.size();
    int start = -1, end;
    int si = 0, ei = n-1, mid;
    while(si <= ei){
        mid = (si+ei)/2;
        if(A[mid] < B){
            si = mid+1;
        }
        else if(A[mid] > B) ei = mid-1;
        else{
            start = mid;
            ei = mid-1;
        }
    }
    
    vector<int> output;
    
    if(start == -1){
        output.pb(-1);
        output.pb(-1);
        return output;
    }
    
    si = 0; ei = n-1;
    while(si <= ei){
        mid = (si+ei)/2;
        if(A[mid] < B){
            si = mid+1;
        }
        else if(A[mid] > B) ei = mid-1;
        else{
            end = mid;
            si = mid+1;
        }
    }
    
    output.pb(start);
    output.pb(end);
    return output;
}

