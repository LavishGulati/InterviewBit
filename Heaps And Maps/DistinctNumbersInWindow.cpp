#define pb push_back

vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    
    map<int, int> m;
    for(int i = 0; i < B; i++){
        m[A[i]]++;
    }
    
    vector<int> output;
    for(int i = B; i < n; i++){
        output.pb(m.size());
        if(m[A[i-B]] == 1){
            m.erase(A[i-B]);
        }
        else m[A[i-B]]--;
        
        m[A[i]]++;
    }
    
    output.pb(m.size());
    return output;
}
