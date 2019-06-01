int Solution::diffPossible(vector<int> &A, int B) {
    int n = A.size();
    if(n == 1) return 0;
    int i = 0;
    int j = i+1;
    while(i < n){
        while(j < n && A[j]-A[i] < B) j++;
        if(j < n && A[j]-A[i] == B) return 1;
        i++;
        if(j == i) j++;
    }
    return 0;
}
