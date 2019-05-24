typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define s second
#define f first

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    vector<pii> helper;
    for(int i = 0; i < n; i++){
        helper.pb(mp(arrive[i], 1));
    }
    for(int i = 0; i < n; i++){
        helper.pb(mp(depart[i], -1));
    }
    
    sort(all(helper));
    
    int total = 0;
    for(int i = 0; i < 2*n; i++){
        if(helper[i].s == 1) total++;
        else total--;
        
        if(total > K) return 0;
    }
    
    return 1;
}

