void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    int num = n-1;
    for(int i = 0; i < n/2; i++){
        int x = n-i;
        for(int j = 0; j < num; j++){
            int temp = A[i][j+i];
            A[i][j+i] = A[x-1-j][i];
            A[x-1-j][i] = A[x-1][x-1-j];
            A[x-1][x-1-j] = A[j+i][x-1];
            A[j+i][x-1] = temp;
        }
        num -= 2;
    }
}

