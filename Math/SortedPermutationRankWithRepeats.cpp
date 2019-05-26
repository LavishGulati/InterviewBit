#define MOD 1000003
#define f first
#define s second
typedef long long ll;

ll power(ll x, ll n, ll m){
    if(n == 0) return 1;
    else if(n == 1) return x%m;
    
    if(n%2 == 0){
        ll y = power(x, n/2, m);
        return (y*y)%m;
    }
    else{
        ll y = power(x, (n-1)/2, m);
        return (x*((y*y)%m))%m;
    }
}

int Solution::findRank(string A) {
    ll n = A.length();
    
    ll factorial[n+1];
    factorial[0] = factorial[1] = 1;
    for(ll i = 2; i < n+1; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    
    map<char, ll> m;
    for(ll i = 0; i < n; i++){
        m[A[i]]++;
    }
    
    ll total = 0;
    for(ll i = 0; i < n; i++){
        set<char> smaller;
        for(ll j = i+1; j < n; j++){
            if(A[j] < A[i]) smaller.insert(A[j]);
        }
        
        for(auto j = smaller.begin(); j != smaller.end(); j++){
            ll SmallAns = factorial[n-i-1];
            ll helper = 1;
            for(auto k = m.begin(); k != m.end(); k++){
                if(k->s > 0){
                    if(k->f == *j){
                        helper = (helper*factorial[k->s - 1])%MOD;
                    }
                    else{
                        helper = (helper*factorial[k->s])%MOD;
                    }
                }
            }
            helper = power(helper, MOD-2, MOD);
            SmallAns = (SmallAns*helper)%MOD;
            total = (total+SmallAns)%MOD;
        }
        
        m[A[i]]--;
    }
    
    return (total+1)%MOD;
}
