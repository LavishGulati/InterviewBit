#define pb push_back

vector<vector<int>> output;

void MakeCombinations(int id, int A, int B, vector<int> helper){
    if(helper.size() > B) return;
    if(id > A){
        if(helper.size() < B) return;
        
        output.pb(helper);
        return;
    }
    
    helper.pb(id);
    MakeCombinations(id+1, A, B, helper);
    helper.pop_back();
    
    MakeCombinations(id+1, A, B, helper);
}

vector<vector<int> > Solution::combine(int A, int B) {
    output.clear();
    vector<int> helper;
    MakeCombinations(1, A, B, helper);
    return output;
}
