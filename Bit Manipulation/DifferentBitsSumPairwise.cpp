#define MOD 1000000007
typedef long long ll;

int Solution::cntBits(vector<int> &A) {
    int n = A.size();
    ll NumZero, NumOne;
    ll total = 0;
    for(int i = 0; i < 32; i++){
        NumZero = NumOne = 0;
        for(int j = 0; j < n; j++){
            if(A[j]%2 == 1) NumOne++;
            else NumZero++;
            
            A[j] /= 2;
        }
        total = (total+((NumZero*NumOne)%MOD))%MOD;
    }
    return (total*2)%MOD;
}
