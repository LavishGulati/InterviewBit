typedef long long ll;

ll answer;

void calculate(const vector<int> &A, ll si, ll ei){
    if(si > ei) return;
    
    if(si == ei){
        answer = max(answer, ll(A[si]));
        return;
    }
    
    ll neg = 0;
    ll prod = 1;
    for(ll i = si; i <= ei; i++){
        if(A[i] < 0) neg++;
        prod *= A[i];
    }
    
    if((neg%2) == 0){
        answer = max(answer, prod);
        return;
    }

    ll a, b;
    a = 1; b = prod;
    for(ll i = si; i <= ei; i++){
        b /= A[i];
        if(A[i] < 0){
            if(i == si) answer = max(answer, b);
            else answer = max(max(a, b), answer);
        }
        a *= A[i];
    }
}

int Solution::maxProduct(const vector<int> &A) {
    ll n = A.size();
    answer = LLONG_MIN;
    
    ll si = 0;
    bool IsZero = false;
    for(ll i = 0; i < n; i++){
        if(A[i] == 0){
            IsZero = true;
            calculate(A, si, i-1);
            si = i+1;
        }
    }
    calculate(A, si, n-1);
    if(IsZero && answer < 0){
        answer = 0;
    }
    return answer;
}
