#define pb push_back

vector<int> Solution::flip(string A) {
    bool allOnes = true;
    int n = A.length();
    for(int i = 0; i < n; i++){
        if(A[i] == '0'){
            allOnes = false;
            break;
        }
    }
    
    vector<int> output;
    
    if(allOnes){
        return output;
    }
    
    int helper[n];
    if(A[0] == '1') helper[0] = -1;
    else helper[0] = 1;
    
    for(int i = 1; i < n; i++){
        if(A[i] == '1') helper[i] = helper[i-1]-1;
        else helper[i] = helper[i-1]+1;
    }
    
    int MaxChange = INT_MIN;
    int SmallestNo = 0;
    int x, y;
    for(int i = 0; i < n; i++){
        if(MaxChange < helper[i]-helper[SmallestNo]){
            MaxChange = helper[i]-helper[SmallestNo];
            x = SmallestNo;
            y = i;
        }
        
        if(helper[i] < helper[SmallestNo]){
            SmallestNo = i;
        }
    }
    
    output.pb(x+1);
    output.pb(y+1);
}

