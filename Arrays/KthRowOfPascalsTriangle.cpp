#define pb push_back

vector<int> Solution::getRow(int A) {
    vector<int> helper;
    vector<int> output;
    
    helper.pb(1);
    int size = 2;
    for(int i = 1; i <= A; i++){
        for(int j = 0; j < size; j++){
            if(j == 0){
                output.pb(1);
            }
            else if(j >= int(ceil(((double)size)/2))){
                output.pb(output[size-1-j]);
            }
            else{
                output.pb(helper[j]+helper[j-1]);
            }
        }    
        
        helper.clear();
        for(int j = 0; j < output.size(); j++){
            helper.pb(output[j]);
        }
        output.clear();
        size++;
    }
    
    
    return helper;
}

