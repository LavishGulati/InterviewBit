#define pb push_back

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> output;
    int i = 0, j = 0;
    
    while(i < A.size() && j < B.size()){
        if(A[i] < B[j]) i++;
        else if(B[j] < A[i]) j++;
        else{
            output.pb(A[i]);
            i++; j++;
        }
    }
    
    return output;
}
