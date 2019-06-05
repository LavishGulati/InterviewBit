#define pb push_back

vector<int> Solution::grayCode(int A) {
    vector<int> output;
    output.pb(0);
    output.pb(1);
    
    int power[A+1];
    power[0] = 1;
    for(int i = 1; i <= A; i++) power[i] = power[i-1]*2;
    
    vector<int> helper;
    int n;
    for(int i = 1; i < A; i++){
        n = output.size();
        helper = output;
        for(int j = n-1; j >= 0; j--){
            helper.pb(output[j]+power[i]);
        }
        output = helper;
        helper.clear();
    }
    
    return output;
}
