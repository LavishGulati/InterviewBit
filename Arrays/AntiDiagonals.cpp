#define pb push_back

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    
    vector<vector<int>> output;
    for(int j = 0; j < n; j++){
        vector<int> v;
        int k = j;
        for(int i = 0; i <= j; i++){
            v.pb(A[i][k]);
            k--;
        }
        output.pb(v);
    }
    
    for(int i = 1; i < n; i++){
        vector<int> v;
        int k = i;
        for(int j = n-1; j >= i; j--){
            v.pb(A[k][j]);
            k++;
        }
        output.pb(v);
    }
    
    return output;
}

