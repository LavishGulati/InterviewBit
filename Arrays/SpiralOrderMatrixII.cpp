typedef long long ll;
#define pb push_back
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> output;
    
    for(int i = 0; i < A; i++){
        vector<int> NewVector;
        for(int j = 0; j < A; j++){
            NewVector.pb(0);
        }
        output.pb(NewVector);
    }
    
    int i = 0;
    int j = 0;
    string direction = "RIGHT";
    
    ll num = 1;
    while(num <= A*A){
        output[i][j] = num;
        num++;
        
        if(direction == "RIGHT"){
            j++;
            if(j == A || output[i][j] != 0){
                j--;
                i++;
                direction = "DOWN";
            }
        }
        else if(direction == "DOWN"){
            i++;
            if(i == A || output[i][j] != 0){
                i--;
                j--;
                direction = "LEFT";
            }
        }
        else if(direction == "LEFT"){
            j--;
            if(j == -1 || output[i][j] != 0){
                j++;
                i--;
                direction = "UP";
            }
        }
        else{
            i--;
            if(i == -1 || output[i][j] != 0){
                i++;
                j++;
                direction = "RIGHT";
            }
        }
    }
    
    return output;
}

