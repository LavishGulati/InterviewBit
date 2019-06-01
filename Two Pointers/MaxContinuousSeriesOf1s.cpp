#define pb push_back

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = A.size();
    
    int i = 0, j = 0, k;
    int si, ei;
    int MaxOne = INT_MIN, NumZero = 0, FirstZero;
    
    while(i < n){
        while(j < n && NumZero < B){
            if(A[j] == 0){
                NumZero++;
            }
            j++;
        }
        k = i;
        while(A[k] != 0) k++;
        FirstZero = k;
        k = j;
        while(k < n && A[k] == 1) k++;
        if(k-i > MaxOne){
            MaxOne = k-i;
            si = i;
            ei = k;
        }
        i = max(FirstZero+1, i+1);
        NumZero--;
    }
    
    vector<int> output;
    for(i = si; i < ei; i++) output.pb(i);
    return output;
}
