#define pb push_back
#define all(x) x.begin(), x.end()

int Solution::anytwo(string A) {
    int n = A.length();
    
    vector<int> helper[256];
    for(int i = 0; i < n; i++){
        helper[A[i]].pb(i);
    }
    
    for(int i = 0; i < 256; i++){
        if(helper[i].size() >= 3) return 1;
        sort(all(helper[i]));
    }
    
    
    for(int i = 0; i < 256; i++){
        if(helper[i].size() > 1){
            for(int j = i+1; j < 256; j++){
                if(helper[j].size() > 1){
                    if(helper[i][0] < helper[j][0] && helper[j][1] < helper[i][1]){
                        // do nothing
                    }
                    else if(helper[j][0] < helper[i][0] && helper[i][1] < helper[j][1]){
                        // do nothing
                    }
                    else return 1;
                }
            }
        }
    }
    
    return 0;
}
