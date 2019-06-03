#define pb push_back

int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size()-1;
    int buckets[int(ceil(sqrt(n)))];
    for(int i = 0; i < int(ceil(sqrt(n))); i++) buckets[i] = 0;
    
    int id;
    for(int i = 0; i <= n; i++){
        if(A[i]/sqrt(n) == floor(A[i]/sqrt(n))){
            id = int(floor(A[i]/sqrt(n)))-1;
        }
        else{
            id = int(floor(A[i]/sqrt(n)));
        }
        
        buckets[id]++;
    }
    
    vector<int> target;
    for(int i = 0; i < int(ceil(sqrt(n))); i++){
        if(buckets[i] > sqrt(n)){
            target.pb(i);
        }
    }
    if(target[target.size()-1] != int(ceil(sqrt(n)))-1){
        target.pb(int(ceil(sqrt(n)))-1);
    }
    
    set<int> s;
    for(int j = 0; j < target.size(); j++){
        for(int i = 0; i <= n; i++){
            if(A[i]/sqrt(n) == floor(A[i]/sqrt(n))) id = int(floor(A[i]/sqrt(n)))-1;
            else id = int(floor(A[i]/sqrt(n)));
            
            if(id == target[j]){
                if(s.find(A[i]) != s.end()) return A[i];
                else s.insert(A[i]);
            }
        }
        s.clear();
    }
    
    return -1;
}
