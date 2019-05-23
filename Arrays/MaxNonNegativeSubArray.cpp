typedef long long ll;
#define pb push_back

vector<int> Solution::maxset(vector<int> &A) {
    ll n = A.size();
    
    ll i = 0;
    ll j = 0;
    ll x, y;
    ll total = 0;
    ll MaxSum = INT_MIN;
    ll MaxLength = INT_MIN;
    
    while(j < n){
        if(A[j] >= 0){
            total += A[j];
            j++;
        }
        else{
            if(total > MaxSum){
                total = MaxSum;
                MaxLength = j-i;
                x = i;
                y = j-1;
            }
            else if(total == MaxSum && j-i > MaxLength){
                MaxLength = j-i;
                x = i;
                y = j-1;
            }
            
            j++;
            i = j;
            total = 0;
        }
    }
    
    if(total > MaxSum){
        total = MaxSum;
        MaxLength = j-i;
        x = i;
        y = j-1;
    }
    else if(total == MaxSum && j-i > MaxLength){
        MaxLength = j-i;
        x = i;
        y = j-1;
    }
    
    vector<int> output;
    for(ll i = x; i <= y; i++){
        output.pb(A[i]);
    }
    return output;
}

