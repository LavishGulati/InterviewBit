#define all(x) x.begin(), x.end()
#define MOD 1000007
typedef long long ll;

int Solution::coinchange2(vector<int> &A, int B) {
    ll n = A.size();
    // sort(all(A));
    ll helper[B+1];
    ll output[B+1];
    for(ll i = 0; i <= B; i++) output[i] = 0;
    output[0] = 1;
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j <= B; j++){
            helper[j] = output[j];
            output[j] = 0;
        }
        output[0] = 1;
        for(ll j = 1; j <= B; j++){
            output[j] = (output[j]+helper[j])%MOD;
            if(j-A[i] >= 0) output[j] = (output[j]+output[j-A[i]])%MOD;
        }
    }
    return output[B];
}
