typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back

vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    int CumSum[n+1];
    CumSum[0] = 0;
    for(int i = 1; i <= n; i++){
        CumSum[i] = CumSum[i-1]+A[i-1];
    }
    
    map<int, pii> m;
    for(int i = 1; i <= n; i++){
        if(CumSum[i] == 0){
            m[0] = mp(0, i);
        }
        else if(m.find(CumSum[i]) == m.end()){
            m[CumSum[i]] = mp(i, i);
        }
        else{
            m[CumSum[i]].f = min(m[CumSum[i]].f, i);
            m[CumSum[i]].s = max(m[CumSum[i]].s, i);
        }
    }
    
    int si = -1, ei = -1, MaxLength = 0;
    for(auto i = m.begin(); i != m.end(); i++){
        if((i->s).s-(i->s).f > MaxLength){
            MaxLength = (i->s).s - (i->s).f;
            si = (i->s).f;
            ei = (i->s).s;
        }
        else if((i->s).s-(i->s).f == MaxLength && (i->s).f < si){
            MaxLength = (i->s).s - (i->s).f;
            si = (i->s).f;
            ei = (i->s).s;
        }
    }
    
    vector<int> output;
    if(si != -1){
        for(int i = si; i < ei; i++){
            output.pb(A[i]);
        }
    }
    return output;
}
