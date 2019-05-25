typedef pair<int, int> pii;
#define f first
#define s second

int Solution::repeatedNumber(const vector<int> &A) {
    pii helper[2];
    int n = A.size();
    if(n == 1) return A[0];
    
    int i = 1;
    helper[0].f = A[0];
    helper[0].s = 1;
    while(i < n && A[i] == helper[0].f){
        helper[0].s++;
        i++;
    }
    
    if(i == n) return helper[0].f;
    
    helper[1].f = A[i];
    i++;
    
    helper[1].s = 1;
    for(; i < n; i++){
        if(A[i] == helper[0].f) helper[0].s++;
        else if(A[i] == helper[1].f) helper[1].s++;
        else if(helper[0].s == 0){
            helper[0].f = A[i];
            helper[0].s = 1;
        }
        else if(helper[1].s == 0){
            helper[1].f = A[i];
            helper[1].s = 1;
        }
        else{
            helper[0].s--;
            helper[1].s--;
        }
    }
    
    int x, count;
    if(helper[0].s > 0){
        count = 0;
        x = helper[0].f;
        for(int i = 0; i < n; i++){
            if(A[i] == x) count++;
        }
        if(count > n/3) return x;
    }
    if(helper[1].s > 0){
        count = 0;
        x = helper[1].f;
        for(int i = 0; i < n; i++){
            if(A[i] == x) count++;
        }
        if(count > n/3) return x;
    }
    return -1;
}
