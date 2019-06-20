int Solution::bulbs(vector<int> &A) {
    int n = A.size();
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(answer%2 == 0){
            if(A[i] == 0){
                answer++;
            }
        }
        else{
            if(A[i] == 1){
                answer++;
            }
        }
    }
    
    return answer;
}
