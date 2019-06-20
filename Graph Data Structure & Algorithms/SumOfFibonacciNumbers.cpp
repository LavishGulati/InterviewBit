#define pb push_back

int Solution::fibsum(int A) {
    if(A == 1) return 1;
    if(A == 0) return 0;
    
    queue<int> q;
    q.push(1);
    q.push(1);
    
    int x;
    while(1){
        x = q.front();
        q.pop();
        x += q.front();
        if(x <= A) q.push(x);
        else break;
    }
    
    x = q.front();
    return 1+fibsum(A-x);
}
