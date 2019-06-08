#define pb push_back
#define s second

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    
    map< vector<int>, vector<int> > m;
    
    vector<int> helper;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++) helper.pb(0);
        
        for(int j = 0; j < A[i].length(); j++){
            helper[A[i][j]-'a']++;
        }
        
        m[helper].pb(i+1);
        helper.clear();
    }
    
    vector< vector<int> > output;
    for(auto i = m.begin(); i != m.end(); i++){
        output.pb(i->s);
    }
    return output;
}
