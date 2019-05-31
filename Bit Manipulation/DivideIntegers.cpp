typedef long long ll;

int Solution::divide(int A, int B) {
    if(B == 0) return INT_MAX;
    if(A == 0) return 0;
    if(A == INT_MIN && B == -1) return INT_MAX;
    
    ll answer = 0;
    ll a = abs(ll(A)), b = abs(ll(B));
    if(b > a) return 0;
    while(a >= b){
        a -= b;
        answer++;
    }
    
    if((A < 0 && B > 0) || (A > 0 && B < 0)) return 0-answer;
    else return answer;
}
