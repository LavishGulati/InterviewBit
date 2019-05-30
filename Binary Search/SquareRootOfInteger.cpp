typedef long long ll;

int Solution::sqrt(int A) {
    ll si = 0;
    ll ei = A;
    ll mid, answer;
    
    while(si <= ei){
        mid = (si+ei)/2;
        if(mid*mid <= A){
            answer = mid;
            si = mid+1;
        }
        else if(mid*mid > A) ei = mid-1;
    }
    
    return answer;
}

