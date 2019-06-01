#define pb push_back

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> output;
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()){
        if(A[i] <= B[j]){
            output.pb(A[i]);
            i++;
        }
        else{
            output.pb(B[j]);
            j++;
        }
    }
    
    while(i < A.size()){
        output.pb(A[i]);
        i++;
    }
    
    while(j < B.size()){
        output.pb(B[j]);
        j++;
    }
    
    A.clear();
    for(int i = 0; i < output.size(); i++) A.pb(output[i]);
}
