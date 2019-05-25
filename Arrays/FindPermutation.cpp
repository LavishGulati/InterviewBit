#define pb push_back

vector<int> Solution::findPerm(const string A, int B) {
    int NumI = 0;
    for(int i = 0; i < B-1; i++){
        if(A[i] == 'I') NumI++;
    }
    
    vector<int> output;
    output.pb(B-NumI);
    
    int CurrentSmaller = B-NumI-1;
    int CurrentLarger = B-NumI+1;
    for(int i = 0; i < B-1; i++){
        if(A[i] == 'D'){
            output.pb(CurrentSmaller);
            CurrentSmaller--;
        }
        else{
            output.pb(CurrentLarger);
            CurrentLarger++;
        }
    }
    return output;
}

