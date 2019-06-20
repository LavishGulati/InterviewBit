class state{
public:
    int prev;
    bool x;
    
    state(){
        
    }
    
    state(int prev, bool x){
        this->prev = prev;
        this->x = x;
    }
};

string BuildAnswer(int cur, state *helper){
    if(cur == 1){
        return "1";
    }
    
    char c = (helper[cur].x == false) ? '0' : '1';
    return BuildAnswer(helper[cur].prev, helper)+c;
}

string Solution::multiple(int A) {
    if(A == 1) return "1";
    
    state *helper = new state[A];
    helper[1] = state(-1, true);
    
    bool IsVisited[A];
    for(int i = 0; i < A; i++) IsVisited[i] = false;
    
    queue<int> q;
    q.push(1);
    IsVisited[1] = true;
    int x, cur;
    while(!q.empty()){
        x = q.front();
        q.pop();
        cur = (x*10)%A;
        if(!IsVisited[cur]){
            q.push(cur);
            IsVisited[cur] = true;
            helper[cur] = state(x, false);
            if(cur == 0) break;
        }
        cur = (x*10+1)%A;
        if(!IsVisited[cur]){
            q.push(cur);
            IsVisited[cur] = true;
            helper[cur] = state(x, true);
            if(cur == 0) break;
        }
    }
    
    return BuildAnswer(0, helper);
}
