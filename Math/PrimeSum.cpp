#define pb push_back
typedef long long ll;
#define all(x) x.begin(), x.end()

vector<int> Solution::primesum(int A) {
    vector<bool> sieve;
    for(ll i = 0; i < A+1; i++) sieve.pb(true);
    
    sieve[0] = false;
    sieve[1] = false;
    for(ll i = 2; i <= sqrt(A+1); i++){
        if(sieve[i]){
            ll j = i*i;
            while(j < A+1){
                sieve[j] = false;
                j += i;
            }
        }
    }
    
    vector<int> primes;
    for(int i = 0; i < A+1; i++){
        if(sieve[i]) primes.pb(i);
    }
    
    vector<int> output;
    for(int i = 0; i < primes.size(); i++){
        auto it = find(all(primes), A-primes[i]);
        if(it != primes.end()){
            output.pb(primes[i]);
            output.pb(A-primes[i]);
            return output;
        }
    }
    
}

