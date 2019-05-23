typedef long long ll;
#define pb push_back

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> output;
    ll n = A.size();
    
    ll sum = 0, SumOfSq = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
        SumOfSq += ((ll)A[i])*(ll(A[i]));
    }
    
    ll diffAB = (n*(n+1))/2 - sum;
    ll DiffOfSq = (n*(n+1)*(2*n+1))/6 - SumOfSq;
    
    if(diffAB == 0){
        cout << "ERROR" << endl;
        return output;
    }
    ll sumAB = DiffOfSq/diffAB;
    
    output.pb((int)((sumAB-diffAB)/2));
    output.pb(int((sumAB+diffAB)/2));
    return output;
}

