#define all(x) x.begin(), x.end()
#define pb push_back

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(all(A));
    int n = A.size();
    
    set< vector<int> > s;
    vector<int> answer;
    
    int i = 0, j, k;
    while(i < n){
        j = i+1;
        k = n-1;
        while(j < k){
            if(A[j]+A[k] > -A[i]) k--;
            else if(A[j]+A[k] < -A[i]) j++;
            else{
                answer.clear();
                answer.pb(A[i]);
                answer.pb(A[j]);
                answer.pb(A[k]);
                sort(all(answer));
                s.insert(answer);
                j++;
            }
        }
        i++;
    }
    
    vector< vector<int> > output;
    for(auto i = s.begin(); i != s.end(); i++){
        output.pb(*i);
    }
    
    return output;
}
