typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

int gcd(int a, int b){
    if(a == 0) return b;
    if(b == 0) return a;
    if(a < 0) return gcd(-1*a, b);
    if(b < 0) return gcd(a, -1*b);
    if(a > b) return gcd(b, a);
    return gcd(b%a, a);
}

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    map<pii, int> m;
    int answer = 0;
    
    int n = X.size();
    int same, CurMax, a, b, x;
    for(int i = 0; i < n; i++){
        m.clear();
        same = 1;
        CurMax = 0;
        for(int j = i+1; j < n; j++){
            a = X[i]-X[j];
            b = Y[i]-Y[j];
            if(a == 0 && b == 0){
                same++;
                continue;
            }
            if(a < 0){
                a *= -1;
                b *= -1;
            }
            x = gcd(a, b);
            m[mp(a/x, b/x)]++;
            CurMax = max(CurMax, m[mp(a/x, b/x)]);
        }
        CurMax += same;
        answer = max(answer, CurMax);
    }
    
    return answer;
}
