#define pb push_back

vector< vector<int> > output;

void MakePermutations(int id, bool *IsIncluded, vector<int> &A, vector<int> &helper){
    if(id == A.size()){
        output.pb(helper);
        return;
    }
    
    for(int i = 0; i < A.size(); i++){
        if(!IsIncluded[i]){
            IsIncluded[i] = true;
            helper.pb(A[i]);
            MakePermutations(id+1, IsIncluded, A, helper);
            helper.pop_back();
            IsIncluded[i] = false;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    output.clear();
    int n = A.size();
    bool *IsIncluded = new bool[n];
    for(int i = 0; i < n; i++) IsIncluded[i] = false;
    
    vector<int> helper;
    MakePermutations(0, IsIncluded, A, helper);
    return output;
}
