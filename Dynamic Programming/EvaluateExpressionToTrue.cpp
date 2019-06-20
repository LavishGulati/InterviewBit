#define MOD 1003
typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

map<string, pii> m;

pii expression(string A){
    if(A.length() == 1){
        if(A == "T") return mp(1, 0);
        else return mp(0, 1);
    }
    
    if(m.find(A) != m.end()) return m[A];
    
    pii ans;
    ans.f = ans.s = 0;
    for(int i = 1; i < A.length(); i += 2){
        pii left = expression(A.substr(0, i));
        pii right = expression(A.substr(i+1));
        
        if(A[i] == '|'){
            ans.f = (ans.f+(left.f*right.f)%MOD)%MOD;
            ans.f = (ans.f+(left.f*right.s)%MOD)%MOD;
            ans.f = (ans.f+(left.s*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.s)%MOD)%MOD;
        }
        else if(A[i] == '&'){
            ans.f = (ans.f+(left.f*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.s)%MOD)%MOD;
            ans.s = (ans.s+(left.f*right.s)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.f)%MOD)%MOD;
        }
        else{
            ans.f = (ans.f+(left.f*right.s)%MOD)%MOD;
            ans.f = (ans.f+(left.s*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.f*right.f)%MOD)%MOD;
            ans.s = (ans.s+(left.s*right.s)%MOD)%MOD;
        }
    }
    
    m[A] = ans;
    return ans;
}

int Solution::cnttrue(string A) {
    m.clear();
    return expression(A).f;
}
