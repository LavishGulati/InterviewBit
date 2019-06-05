typedef long long ll;

string output;

bool GetPermutationHelper(ll id, ll A, ll B, string helper, bool *IsIncluded, ll *factorial){
    if(id == A){
        if(B == 0){
            output = helper;
            return true;
        }
        else{
            return false;
        }
    }
    
    for(ll i = 1; i <= A; i++){
        if(!IsIncluded[i]){
            if(i*factorial[A-id-1] >= B){
                IsIncluded[i] = true;
                if(GetPermutationHelper(id+1, A, B-((i-1)*factorial[A-id-1]), helper+to_string(i), IsIncluded, factorial)){
                    return true;
                }
                IsIncluded[i] = false;
            }
        }
    }
    
    return false;
}


string Solution::getPermutation(int A, int B) {
    string helper = "";
    
    ll *factorial = new ll[A];
    factorial[0] = 1;
    for(ll i = 1; i < A; i++){
        factorial[i] = factorial[i-1]*i;
    }
    
    bool *IsIncluded = new bool[A+1];
    for(ll i = 0; i <= A; i++) IsIncluded[i] = false;
    GetPermutationHelper(0, A, B, helper, IsIncluded, factorial);
    return output;
}
