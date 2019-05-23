vector<int> Solution::plusOne(vector<int> &A) {
    
    
    bool allNines = true;
    for(int i = 0; i < A.size(); i++){
        if(A[i] != 9){
            allNines = false;
            break;
        }
    }
    
    if(allNines){
        vector<int> output;
        output.push_back(1);
        for(int i = 0; i < A.size(); i++){
            output.push_back(0);
        }
        return output;
    }
    
    vector<int> output = A;
    for(int i = output.size()-1; i >= 0; i--){
        if(output[i] == 9){
            output[i] = 0;
        }
        else{
            output[i]++;
            break;
        }
    }
    vector<int> finalOutput;
    int i;
    for(i = 0; i < output.size(); i++){
        if(output[i] != 0) break;
    }
    for(; i < output.size(); i++){
        finalOutput.push_back(output[i]);
    }
    return finalOutput;
}

