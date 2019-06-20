typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    
    pii a;
    a = mp(A[0], 1);
    for(int i = 1; i < n; i++){
        if(a.s == 0){
            a = mp(A[i], 1);
        }
        else if(a.f == A[i]) a.s++;
        else a.s--;
    }
    
    return a.f;
}
