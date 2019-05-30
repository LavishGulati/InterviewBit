typedef long long ll;

int Solution::atoi(const string A) {
    ll n = A.length();
    ll i, helper, answer;
    if(A[0] == '-' || A[0] == '+'){
        i = 1;
        while(i < n && A[i] >= '0' && A[i] <= '9') i++;
        
        if(i == 1 && !(A[i] >= '0' && A[i] <= '9')) return 0;
        
        answer = 0; helper = 1;
        i--;
        while(i > 0){
            answer += (A[i]-'0')*helper;
            helper *= 10;
            i--;
            if(answer > INT_MAX && A[0] == '-') return INT_MIN;
            if(answer > INT_MAX && A[0] == '+') return INT_MAX;
        }
        if(A[0] == '-') return 0-answer;
        else return answer;
    }
    else{
        i = 0;
        while(i < n && A[i] >= '0' && A[i] <= '9') i++;
        
        if(i == 0 && !(A[i] >= '0' && A[i] <= '9')) return 0;
        
        answer = 0; helper = 1;
        i--;
        while(i >= 0){
            answer += (A[i]-'0')*helper;
            helper *= 10;
            i--;
            if(answer > INT_MAX) return INT_MAX;
        }
        return answer;
    }
}

