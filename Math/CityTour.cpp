#define MOD 1000000007
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()

ll power2(ll x, ll n){
    if(x == 0) return 0;
    if(n == 0) return 1;
    if(n == 1) return x%MOD;
    
    if(n%2 == 0){
        ll y = power2(x, n/2);
        return (y*y)%MOD;
    }
    else{
        ll y = power2(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

ll ModInverse(ll x){
    return power2(x, MOD-2);
}

int Solution::solve(int A, vector<int> &B) {
    ll n = B.size();
    ll factorial[A+1];
    factorial[0] = 1;
    factorial[1] = 1;
    for(ll i = 2; i < A+1; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    ll power[A+1];
    power[0] = 1;
    for(ll i = 1; i < A+1; i++){
        power[i] = (power[i-1]*2)%MOD;
    }
    
    sort(all(B));
    
    vector<ll> InBetween;
    InBetween.pb(B[0]-1);
    for(ll i = 0; i < n-1; i++){
        InBetween.pb(B[i+1]-B[i]-1);
    }
    InBetween.pb(A-B[n-1]);
    
    ll answer = 1;
    for(ll i = 1; i < InBetween.size()-1; i++){
        if(InBetween[i] == 0) continue;
        answer = (answer*power[InBetween[i]-1])%MOD;
    }
    
    ll total = 0;
    for(ll i = 0; i < InBetween.size(); i++) total += InBetween[i];
    
    answer = (answer*factorial[total])%MOD;
    ll prod = 1;
    for(ll i = 0; i < InBetween.size(); i++){
        prod = (prod*factorial[InBetween[i]])%MOD;
    }
    answer = (answer*ModInverse(prod))%MOD;
    
    return answer;
}
