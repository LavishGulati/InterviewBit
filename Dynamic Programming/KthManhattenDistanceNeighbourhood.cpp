#define pb push_back

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    int m = B[0].size();
    int helper[n][m];
    int output[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            output[i][j] = B[i][j];
        }
    }
    
    while(A > 0){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                helper[i][j] = output[i][j];
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = helper[i][j];
                if(i-1 >= 0) x = max(x, helper[i-1][j]);
                if(j+1 < m) x = max(x, helper[i][j+1]);
                if(j-1 >= 0) x = max(x, helper[i][j-1]);
                if(i+1 < n) x = max(x, helper[i+1][j]);
                output[i][j] = x;
            }
        }
        A--;
    }
    
    vector< vector<int> > answer;
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.clear();
        for(int j = 0; j < m; j++){
            v.pb(output[i][j]);
        }
        answer.pb(v);
    }
    return answer;
}
