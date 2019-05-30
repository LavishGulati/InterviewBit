#define MOD 1000000007
typedef long long ll;
#define pb push_back

ll *lps(string s){
    ll n = s.length();
    ll *output = new ll[n];
    output[0] = 0;
    ll len = 0;
    for(ll i = 1; i < n; i++){
        if(s[len] == s[i]){
            len++;
            output[i] = len;
        }
        else{
            if(len == 0){
                output[i] = 0;
            }
            else{
                len = output[len-1];
                i--;
            }
        }
    }
    return output;
}

ll power(ll x, ll n){
    if(n == 0) return 1;
    if(n == 1) return x%MOD;
    
    if(n%2 == 0){
        ll y = power(x, n/2);
        return (y*y)%MOD;
    }
    else{
        ll y = power(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

int Solution::solve(vector<string> &A) {
    ll n = A.size();
    vector<ll> answer;
    ll *helper;
    ll RecurringLength, m, j, x;
    for(ll i = 0; i < n; i++){
        m = A[i].size();
        helper = lps(A[i]);
        if((m%(m-helper[m-1])) == 0) RecurringLength = m-helper[m-1];
        else RecurringLength = m;
        
        for(ll j = 1; ; j++){
            x = (j*(j+1))/2;
            if(x%RecurringLength == 0){
                answer.pb(j);
                break;
            }
        }
        free(helper);
    }
    
    map<ll, ll> mp;
    
    for(ll i = 0; i < answer.size(); i++){
        j = 0;
        m = answer[i];
        while(m%2 == 0){
            j++;
            m /= 2;
        }
        
        mp[2] = max(mp[2], j);
        
        for(ll k = 3; k <= sqrt(answer[i]); k += 2){
            j = 0;
            while(m%k == 0){
                j++;
                m /= k;
            }
            mp[k] = max(mp[k], j);
        }
        
        if(m > 2){
            mp[m] = max(mp[m], ll(1));
        }
    }
    
    ll output = 1;
    for(auto i = mp.begin(); i != mp.end(); i++){
        output = (output*power(i->first, i->second))%MOD;
    }
    return output;
}

