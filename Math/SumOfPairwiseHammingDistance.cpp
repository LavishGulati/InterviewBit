typedef long long ll;
#define MOD 1000000007

int Solution::hammingDistance(const vector<int> &A) {
    ll n = A.size();
    
    ll MaxEl = INT_MIN;
    for(ll i = 0; i < n; i++){
        MaxEl = max((ll)A[i], MaxEl);
    }
    
    ll d = ll(ceil(log2(MaxEl)+1));
    
    ll NumZero, NumOne;
    ll total = 0;
    for(int i = 0; i < d; i++){
        NumZero = NumOne = 0;
        for(ll j = 0; j < n; j++){
            ll ans = (A[j]>>i)&1;
            if(ans == 0) NumZero++;
            else NumOne++;
        }
        total += (NumZero*NumOne)%MOD;
    }
    return (2*total)%MOD;
}

