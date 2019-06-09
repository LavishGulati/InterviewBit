#define MOD 1000000007
typedef long long ll;

ll factorial[101];
ll Power2Sum[101];
ll power2[101];

ll power(ll x, ll n){
    if(n == 0) return 1;
    else if(n == 1) return x%MOD;
    
    ll y;
    if(n%2 == 0){
        y = power(x, n/2);
        return (y*y)%MOD;
    }
    else{
        y = power(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

ll ModInverse(ll x){
    return power(x, MOD-2);
}

ll WaysToFormMaxHeap(ll n){
    if(n == 1 || n == 0) return 1;
    
    ll h = floor(log2(n));
    ll x = Power2Sum[h-1];
    ll l = (x-1)/2;
    l += min(power2[h-1], n-x);
    ll answer = factorial[n-1];
    answer = (answer*ModInverse(factorial[l]))%MOD;
    answer = (answer*ModInverse(factorial[n-l-1]))%MOD;
    answer = (answer*WaysToFormMaxHeap(l))%MOD;
    answer = (answer*WaysToFormMaxHeap(n-1-l))%MOD;
    return answer;
}

int Solution::solve(int A) {
    factorial[0] = 1;
    for(ll i = 1; i < 101; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    
    power2[0] = 1;
    Power2Sum[0] = 1;
    ll x = 1;
    for(ll i = 1; i < 101; i++){
        x = (x*2)%MOD;
        Power2Sum[i] = (Power2Sum[i-1]+x)%MOD;
        power2[i] = x;
    }
    
    return WaysToFormMaxHeap(A);
}
