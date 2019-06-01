#define MOD 1000000007
#define all(x) x.begin(), x.end()
typedef long long ll;

int Solution::nTriang(vector<int> &A) {
    sort(all(A));
    int n = A.size();
    
    ll total = 0;
    
    ll i = n-1, j, k;
    while(i >= 0){
        j = i-1;
        k = 0;
        while(j > k){
            while(k < j && A[k]+A[j] <= A[i]) k++;
            if(k < j){
                total = (total+j-k)%MOD;
                j--;
            }
            else break;
        }
        i--;
    }
    
    return total;
}
