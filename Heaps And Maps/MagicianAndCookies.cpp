typedef long long ll;
#define MOD 1000000007

int Solution::nchoc(int A, vector<int> &B) {
    int n = B.size();
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        pq.push(B[i]);
    }
    
    ll total = 0, x;
    while(A--){
        x = pq.top();
        total = (total+x)%MOD;
        pq.pop();
        pq.push(x/2);
    }
    return total;
}
