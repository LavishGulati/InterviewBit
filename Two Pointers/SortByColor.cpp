void Solution::sortColors(vector<int> &A) {
    int n = A.size();
    int j = 0, temp;
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < n; i++){
            if(A[i] == k){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j++;
            }
        }
    }
}
