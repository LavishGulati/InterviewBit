typedef long long ll;

string Solution::getPermutation(int A, int B) {
    ll factorial[A];
    factorial[0] = 1;
    for(ll i = 1; i < A; i++){
        if(factorial[i-1] == INT_MAX) factorial[i] = INT_MAX;
        else factorial[i] = min(factorial[i-1]*i, ll(INT_MAX));
    }
    
    string answer = "";
    ll id;
    
    set<ll> s;
    for(ll i = 1; i <= A; i++) s.insert(i);
    
    for(ll i = 0; i < A; i++){
        id = ll(ceil(double(B)/factorial[A-i-1]));
        auto j = s.begin();
        for(ll k = 1; k < id; k++){
            j++;
        }
        answer += to_string(*j);
        s.erase(j);
        B -= (id-1)*factorial[A-i-1];
    }
    return answer;
}
