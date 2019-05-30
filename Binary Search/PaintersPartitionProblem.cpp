#define MOD 10000003
typedef long long ll;

int Solution::paint(int A, int B, vector<int> &C) {
    ll n = C.size();
    ll TotalUnits = 0;
    for(ll i = 0; i < n; i++){
        TotalUnits += C[i];
    }
    
    ll si = 0, ei = TotalUnits;
    ll mid, BoardsPainted, j, i, answer;
    while(si <= ei){
        mid = (si+ei)/2;
        j = 0;
        for(i = 0; i < A; i++){
            BoardsPainted = 0;
            while(j < n && BoardsPainted+C[j] <= mid){
                BoardsPainted += C[j];
                j++;
            }
            if(j == n) break;
        }
        
        if(i >= A){
            si = mid+1;
        }
        else{
            answer = (mid*B)%MOD;
            ei = mid-1;
        }
    }
    
    return answer;
}

