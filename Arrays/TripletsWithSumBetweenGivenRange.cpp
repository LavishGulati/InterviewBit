#define pb push_back
#define all(x) x.begin(), x.end()

int Solution::solve(vector<string> &A) {
    vector<double> buckets[3];
    int n = A.size();
    for(int i = 0; i < n; i++){
        double x = stod(A[i]);
        if(x < 2.0/3.0) buckets[0].pb(x);
        else if(x >= 2.0/3.0 && x <= 1) buckets[1].pb(x);
        else if(x > 1 && x < 2) buckets[2].pb(x);
    }
    
    for(int i = 0; i < 3; i++){
        sort(all(buckets[i]));
    }
    
    int a = buckets[0].size();
    int b = buckets[1].size();
    int c = buckets[2].size();
    if(a >= 3 && buckets[0][a-1]+buckets[0][a-2]+buckets[0][a-3] > 1) return 1;
    if(a >= 2 && c >= 1 && buckets[0][0]+buckets[0][1]+buckets[2][0] < 2) return 1;
    if(a >= 1 && b >= 2 && buckets[0][0]+buckets[1][0]+buckets[1][1] < 2) return 1;
    if(a >= 1 && b >= 1 && c >= 1 && buckets[0][0]+buckets[1][0]+buckets[2][0] < 2) return 1;
    
    for(int i = 0; i < a; i++){
        for(int j = i+1; j < a; j++){
            for(int k = 0; k < b; k++){
                double sum = buckets[0][i]+buckets[0][j]+buckets[1][k];
                if(sum > 1 && sum < 2) return 1;
            }
        }
    }
    
    return 0;
}

