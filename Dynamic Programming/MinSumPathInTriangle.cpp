#define pb push_back

int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    
    vector<int> output;
    vector<int> helper;
    output.pb(A[0][0]);
    for(int i = 1; i < n; i++){
        helper = output;
        output.clear();
        for(int j = 0; j < A[i].size(); j++){
            output.pb(INT_MAX);
        }
        for(int j = 0; j < helper.size(); j++){
            output[j] = min(output[j], helper[j]+A[i][j]);
            output[j+1] = min(output[j+1], helper[j]+A[i][j+1]);
        }
    }
    
    int answer = INT_MAX;
    for(int i = 0; i < output.size(); i++){
        answer = min(answer, output[i]);
    }
    return answer;
}
