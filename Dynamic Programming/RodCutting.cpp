#define pb push_back
typedef pair<long long, long long> pll;
#define f first
#define s second
#define mp make_pair
typedef long long ll;

vector<int> output;

void rod(pll **dp, ll i, ll j, vector<int> &B){
    if(i >= j-1) return;
    
    output.pb(B[dp[i][j].s-1]);
    rod(dp, i, dp[i][j].s, B);
    rod(dp, dp[i][j].s, j, B);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    ll n = B.size(); 
    
    ll input[n+2];
    input[0] = 0;
    input[n+1] = A;
    for(ll i = 1; i <= n; i++){
        input[i] = B[i-1];
    }
    n += 2;
    
    pll **dp = new pll *[n];
    for(ll i = 0; i < n; i++){
        dp[i] = new pll[n];
    }
    
    ll i = 0, j = 1;
    while(j < n){
        dp[i][j] = mp(0, 0);
        i++; j++;
    }
    
    ll col = 2, k, x, ans;
    while(col < n){
        i = 0; j = col;
        while(j < n){
            k = i+1;
            x = LLONG_MAX;
            
            while(k < j){
                if(dp[i][k].f+dp[k][j].f+input[j]-input[i] < x){
                    x = dp[i][k].f+dp[k][j].f+input[j]-input[i];
                    ans = k;
                }
                k++;
            }
            dp[i][j] = mp(x, ans);
            i++; j++;
        }
        col++;
    }
    
    output.clear();
    rod(dp, 0, n-1, B);
    return output;
}
