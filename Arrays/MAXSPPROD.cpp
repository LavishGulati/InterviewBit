typedef long long ll;
typedef pair<long long, long long> pll;
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007

int Solution::maxSpecialProduct(vector<int> &A) {
    ll n = A.size();
    
    stack<pll> LeftSpecialStack;
    ll LeftSpecial[n];
    for(ll i = 0; i < n; i++){
        while(!LeftSpecialStack.empty() && LeftSpecialStack.top().f <= A[i]){
            LeftSpecialStack.pop();
        }
        if(LeftSpecialStack.empty()) LeftSpecial[i] = 0;
        else{
            LeftSpecial[i] = LeftSpecialStack.top().s;
        }
        LeftSpecialStack.push(mp(A[i], i));
    }
    
    stack<pll> RightSpecialStack;
    ll RightSpecial[n];
    for(ll i = n-1; i >= 0; i--){
        while(!RightSpecialStack.empty() && RightSpecialStack.top().f <= A[i]){
            RightSpecialStack.pop();
        }
        if(RightSpecialStack.empty()) RightSpecial[i] = 0;
        else{
            RightSpecial[i] = RightSpecialStack.top().s;
        }
        RightSpecialStack.push(mp(A[i], i));
    }
    
    ll MaxSpecialValue = INT_MIN;
    for(ll i = 0; i < n; i++){
        // cout << A[i] << " " << LeftSpecial[i] << " " << RightSpecial[i] << endl;
        MaxSpecialValue = max(MaxSpecialValue, LeftSpecial[i]*RightSpecial[i]);
    }
    return MaxSpecialValue%MOD;
}

