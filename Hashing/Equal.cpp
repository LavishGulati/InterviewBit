#define pb push_back
typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

bool unequal(int a, int b, int c, int d){
    if(a == b) return false;
    if(a == c) return false;
    if(a == d) return false;
    if(b == c) return false;
    if(c == d) return false;
    if(b == d) return false;
    return true;
}

vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    
    map< int, vector<pii> > m;
    vector<int> output;
    vector<int> helper;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(m.find(A[i]+A[j]) != m.end()){
                for(int k = 0; k < m[A[i]+A[j]].size(); k++){
                    if(unequal(m[A[i]+A[j]][k].f, m[A[i]+A[j]][k].s, i, j)){
                        helper.clear();
                        helper.pb(m[A[i]+A[j]][k].f);
                        helper.pb(m[A[i]+A[j]][k].s);
                        helper.pb(i);
                        helper.pb(j);
                        if(output.size() == 0 || helper < output){
                            output = helper;
                        }
                    }
                }
            }
            
            
            if(m.find(A[i]+A[j]) == m.end()) m[A[i]+A[j]].pb(mp(i, j));
        }
    }
    
    return output;
}
