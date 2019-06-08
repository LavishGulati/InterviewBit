#define pb push_back

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int si, ei;
    
    map<int, int> m;
    vector<int> output;
    for(int i = 0; i < A.size(); i++){
        if(m.find(B-A[i]) == m.end()){
            if(m.find(A[i]) == m.end()) m[A[i]] = i;
        }
        else{
            output.pb(m[B-A[i]]+1);
            output.pb(i+1);
            return output;
        }
    }
    
    return output;
}
