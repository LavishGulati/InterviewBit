int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int NumZero, NumOne;
    int answer = 0;
    
    int power[32];
    power[0] = 1;
    for(int i = 1; i < 32; i++) power[i] = power[i-1]*2;
    
    for(int i = 0; i < 32; i++){
        NumZero = NumOne = 0;
        for(int j = 0; j < n; j++){
            if((A[j]>>i)&1 == 1) NumOne++;
            else NumZero++;
        }
        if(NumOne%3 == 1) answer += power[i]*1;
    }
    
    return answer;
}
