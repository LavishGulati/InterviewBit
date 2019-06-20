#define pb push_back

vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> helper;
    helper.pb(1);
    int id[3] = {0, 0, 0};
    
    int a, b, c, x;
    while(D--){
        a = helper[id[0]]*A;
        b = helper[id[1]]*B;
        c = helper[id[2]]*C;
        x = min(a, min(b, c));
        helper.pb(x);
        
        if(x == a) id[0]++;
        if(x == b) id[1]++;
        if(x == c) id[2]++;
    }
    
    helper.erase(helper.begin());
    return helper;
}
