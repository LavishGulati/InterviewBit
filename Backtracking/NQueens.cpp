#define pb push_back

vector< vector<string> > output;

bool IsSafe(vector<string> &helper, int id, int A){
    int n = helper.size();
    int i, j;
    for(i = 0; i < n; i++){
        if(helper[i][id] == 'Q') return false;
    }
    
    i = n-1; j = id-1;
    while(i >= 0 && j >= 0){
        if(helper[i][j] == 'Q') return false;
        i--; j--;
    }
    
    i = n-1; j = id+1;
    while(i >= 0 && j < A){
        if(helper[i][j] == 'Q') return false;
        i--; j++;
    }
    
    return true;
}

void SolveNQueensHelper(int id, int A, vector<string> &helper){
    if(id == A){
        output.pb(helper);
        return;
    }
    
    string s;
    for(int i = 0; i < A; i++){
        if(IsSafe(helper, i, A)){
            s = "";
            for(int j = 0; j < A; j++){
                if(j == i) s += 'Q';
                else s += '.';
            }

            helper.pb(s);
            SolveNQueensHelper(id+1, A, helper);
            helper.pop_back();
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    output.clear();
    
    vector<string> helper;
    
    SolveNQueensHelper(0, A, helper);
    return output;
}
