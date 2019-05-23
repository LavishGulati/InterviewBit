#define pb push_back

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> output;
    if(A == 0){
        return output;
    }
    
    for(int i = 0; i < A; i++){
        vector<int> NewVector;
        output.pb(NewVector);
    }
    
    output[0].pb(1);
    int size = 2;
    for(int i = 1; i < A; i++){
        for(int j = 0; j < size; j++){
            if(j == 0){
                output[i].pb(1);
            }
            else if(j >= int(ceil(((double)size)/2))){
                output[i].pb(output[i][size-1-j]);
            }
            else{
                output[i].pb(output[i-1][j]+output[i-1][j-1]);
            }
        }    
        
        size++;
    }
    
    
    return output;
}

