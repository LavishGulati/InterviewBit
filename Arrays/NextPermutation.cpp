#define all(x) x.begin(), x.end()

void Solution::nextPermutation(vector<int> &A) {
    bool IsReverseSorted = true;
    int n = A.size();
    
    if(n == 1) return;
    
    for(int i = 1; i < n; i++){
        if(A[i] > A[i-1]){
            IsReverseSorted = false;
            break;
        }
    }

    if(IsReverseSorted){
        sort(all(A));
        return;
    }
    
    int MaxEl = INT_MIN;
    int MaxId = -1;
    for(int i = n-1; i >= 0; i--){
        if(A[i] > A[i-1]){
            MaxEl = A[i];
            MaxId = i;
            break;
        }
    }
    
    int x = A[MaxId-1];
    int NextLargest = INT_MAX;
    int NextLargestId = -1;
    for(int i = MaxId; i < n; i++){
        if(A[i] >= x && A[i] < NextLargest){
            NextLargest = A[i];
            NextLargestId = i;
        }
    }
    
    A[MaxId-1] = NextLargest;
    A[NextLargestId] = x;
    
    // for(int i = 0; i < n; i++) cout << A[i] << " ";
    // cout << endl;
    
    sort(A.begin()+MaxId, A.end());
}

