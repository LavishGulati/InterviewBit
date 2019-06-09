#define all(x) x.begin(), x.end()
#define pb push_back

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    sort(all(A));
    sort(all(B));
    
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == n-1) pq.push(A[i]+B[j]);
            else{
                if(pq.top() < A[i]+B[j]){
                    pq.pop();
                    pq.push(A[i]+B[j]);
                }
                else break;
            }
        }
    }
    
    vector<int> output;
    while(!pq.empty()){
        output.pb(pq.top());
        pq.pop();
    }
    reverse(all(output));
    return output;
}
