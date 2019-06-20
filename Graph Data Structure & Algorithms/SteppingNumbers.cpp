typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()

int digits(int x){
    int d = 0;
    while(x > 0){
        d++;
        x /= 10;
    }
    return d;
}

vector<int> v;

void helper(int id, string s, int d, int A, int B){
    if(id == d){
        if(stoll(s) >= ll(A) && stoll(s) <= ll(B)){
            v.pb(stoi(s));
        }
        return;
    }
    
    char c;
    if(id == 0){
        for(int i = 1; i <= 9; i++){
            c = i+'0';
            helper(id+1, s+c, d, A, B);
        }
    }
    else{
        if(s[id-1]-'0'-1 >= 0){
            c = s[id-1]-1;
            helper(id+1, s+c, d, A, B);
        }
        if(s[id-1]-'0'+1 < 10){
            c = s[id-1]+1;
            helper(id+1, s+c, d, A, B);
        }
    }
}

vector<int> Solution::stepnum(int A, int B) {
    int d1 = digits(A);
    int d2 = digits(B);
    
    vector<int> output;
    if(A == 0) output.pb(0);
    for(int i = max(d1, 1); i <= d2; i++){
        v.clear();
        helper(0, "", i, A, B);
        for(int j = 0; j < v.size(); j++){
            output.pb(v[j]);
        }
    }
    return output;
}
