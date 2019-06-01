int Solution::removeDuplicates(vector<int> &A) {
    int i = 0, j;
    while(i < A.size()){
        j = i+1;
        while(j < A.size() && A[j] == A[i]) j++;
        if(j > i+1){
            A.erase(A.begin()+i+1, A.begin()+j);
        }
        i++;
    }
    return A.size();
}
