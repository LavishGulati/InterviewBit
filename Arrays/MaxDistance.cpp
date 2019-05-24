#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define s second

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n == 0) return -1;
    
    vector<pii> helper;
    for(int i = 0; i < n; i++){
        helper.pb(mp(A[i], i));
    }
    
    sort(all(helper));
    
    int maxJArr[n];
    int maxJ = helper[n-1].s;
    for(int i = n-2; i >= 0; i--){
        maxJArr[i] = maxJ;
        maxJ = max(maxJ, helper[i].s);
    }
    
    int answer = 0;
    for(int i = 0; i < n-1; i++){
        answer = max(maxJArr[i]-helper[i].s, answer);
    }
    
    return answer;
}

