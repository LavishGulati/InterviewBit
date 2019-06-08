typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

bool unequal(int a, int b, int c, int d){
    if(a == b) return false;
    if(a == c) return false;
    if(a == d) return false;
    if(b == c) return false;
    if(c == d) return false;
    if(b == d) return false;
    return true;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    
    vector<int> helper;
    map< int, set<pii> > m;
    set< vector<int> > st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(m.find(B-A[i]-A[j]) != m.end()){
                for(auto k = m[B-A[i]-A[j]].begin(); k != m[B-A[i]-A[j]].end(); k++){
                    if(unequal((*k).f, (*k).s, i, j)){
                        helper.clear();
                        helper.pb(A[i]);
                        helper.pb(A[j]);
                        helper.pb(A[(*k).f]);
                        helper.pb(A[(*k).s]);
                        sort(all(helper));
                        
                        st.insert(helper);
                    }
                }
            }
            
            m[A[i]+A[j]].insert(mp(i, j));
        }
    }

    vector<vector<int>> output;
    for(auto i = st.begin(); i != st.end(); i++){
        output.pb(*i);
    }
    return output;
}
