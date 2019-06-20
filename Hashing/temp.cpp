typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define DBL_MAX numeric_limits<double>::max()

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    int n = X.size();
    if(n == 1) return 1;
    
    int answer = 0, a, b, x;
    map<pii, set<int> > m;
    for(int i = 0; i < n; i++){
        m.clear();
        for(int j = i+1; j < m; j++){
            a = X[i]-X[j];
            b = Y[i]-Y[j];
            if(a < 0){
                a *= -1;
                b *= -1;
            }
            x == __gcd(a, b);
            m[mp(a/x, b/x)]++;
        }
    }
}

