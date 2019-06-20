#define MOD 10000003
#define pb push_back
typedef long long ll;

int Solution::seats(string A) {
    ll n = A.length();
    
    vector<ll> helper;
    for(ll i = 0; i < n; i++){
        if(A[i] == 'x') helper.pb(i);
    }
    
    if(helper.size() == 0) return 0;
    else if(helper.size()%2 == 1){
        ll total = 0;
        ll id = helper.size()/2;
        ll j = helper[id]-1;
        for(ll i = id-1; i >= 0; i--){
            total += j-helper[i];
            j--;
        }
        j = helper[id]+1;
        for(ll i = id+1; i < helper.size(); i++){
            total += helper[i]-j;
            j++;
        }
        return total%MOD;
    }
    else{
        ll a = 0;
        ll id = helper.size()/2;
        ll j = helper[id]-1;
        for(ll i = id-1; i >= 0; i--){
            a += j-helper[i];
            j--;
        }
        j = helper[id]+1;
        for(ll i = id+1; i < helper.size(); i++){
            a += helper[i]-j;
            j++;
        }
        
        ll b = 0;
        id = helper.size()/2 - 1;
        j = helper[id]-1;
        for(ll i = id-1; i >= 0; i--){
            b += j-helper[i];
            j--;
        }
        j = helper[id]+1;
        for(ll i = id+1; i < helper.size(); i++){
            b += helper[i]-j;
            j++;
        }
        
        return min(a,b)%MOD;
    }
}
