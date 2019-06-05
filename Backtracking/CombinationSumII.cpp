#define all(x) x.begin(), x.end()
#define pb push_back

set< vector<int> > s;

void MakeCombinationSum(int id, vector<int> &A, int B, int sum, vector<int> &helper){
    if(sum > B) return;
    if(sum == B){
        s.insert(helper);
        return;
    }
    
    if(id == A.size()) return;
    
    helper.pb(A[id]);
    MakeCombinationSum(id+1, A, B, sum+A[id], helper);
    helper.pop_back();
    
    MakeCombinationSum(id+1, A, B, sum, helper);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(all(A));
    s.clear();
    vector<int> helper;
    MakeCombinationSum(0, A, B, 0, helper);
    
    vector< vector<int> > output;
    for(auto i = s.begin(); i != s.end(); i++){
        output.pb(*i);
    }
    return output;
}
