#define all(x) x.begin(), x.end()
#define pb push_back

vector<vector<int> > Solution::subsets(vector<int> &A) {
    int n = A.size();
    
    vector< vector<int> > output;
    vector<int> helper;
    output.pb(helper);
    int m;
    for(int i = 0; i < n; i++){
        m = output.size();
        for(int j = 0; j < m; j++){
            helper = output[j];
            helper.pb(A[i]);
            output.pb(helper);
        }
    }
    
    set< vector<int> > s;
    for(int i = 0; i < output.size(); i++){
        sort(all(output[i]));
        s.insert(output[i]);
    }
    output.clear();
    for(auto i = s.begin(); i != s.end(); i++){
        output.pb(*i);
    }
    
    return output;
}
