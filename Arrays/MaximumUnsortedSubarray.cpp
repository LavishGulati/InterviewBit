#define pb push_back

vector<int> Solution::subUnsort(vector<int> &A) {
    bool IsSorted = true;
    int n = A.size();
    for(int i = 1; i < n; i++){
        if(A[i] < A[i-1]){
            IsSorted = false;
            break;
        }
    }
    
    vector<int> output;
    
    if(IsSorted){
        output.pb(-1);
        return output;
    };
    
    int x = 0;
    while(x < n && A[x+1] >= A[x]) x++;
    
    int y = n-1;
    while(y >= 0 && A[y-1] <= A[y]) y--;
    
    int _x = x, _y = y;
    while(x >= 0 && A[x] > A[_y]) x--;
    while(y < n && A[_x] > A[y]) y++;
    
    int minEl = INT_MAX, maxEl = INT_MIN;
    for(int i = x+1; i < y; i++){
        minEl = min(minEl, A[i]);
        maxEl = max(maxEl, A[i]);
    }
    
    while(x >= 0 && A[x] > minEl) x--;
    
    while(y < n && maxEl > A[y]) y++;
    
    output.pb(x+1);
    output.pb(y-1);
    return output;
}

