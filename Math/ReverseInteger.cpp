typedef long long ll;

int Solution::reverse(int A) {
    string s = to_string(A);
    string output = "";
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '-') output = '-'+output;
        else output += s[i];
    }
    
    ll n = stoll(output);
    if(n > INT_MAX || n < INT_MIN) return 0;
    else return n;
}

