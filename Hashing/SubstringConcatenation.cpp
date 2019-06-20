#define pb push_back
#define f first
#define s second

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> output;
    
    int n = A.length();
    int m = B.size();
    if(n == 0 || m == 0) return output;
    
    int l = B[0].length();
    
    if(l*m > n) return output;
    
    map<string, int> mp;
    for(int i = 0; i < m; i++) mp[B[i]]++;
    
    map<string, int> m2;
    string s;
    bool ans;
    for(int i = 0; i <= n-m*l; i++){
        m2.clear();
        m2 = mp;
        ans = true;
        for(int j = i; j < i+m*l; j += l){
            s = A.substr(j, l);
            if(m2.find(s) != m2.end()){
                m2[s]--;
            }
        }
        for(auto i : m2){
            if(i.s != 0){
                ans = false;
                break;
            }
        }
        if(ans) output.pb(i);
    }
    
    return output;
}
