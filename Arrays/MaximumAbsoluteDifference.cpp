#define pb push_back
#define all(x) x.begin(), x.end()

int Solution::maxArr(vector<int> &A) {
    int n = A.size();
        
    vector<int> helper1;
    for(int i = 0; i < n; i++){
        helper1.pb(A[i]+i);
    }
    
    vector<int> helper2;
    for(int i = 0; i < n; i++){
        helper2.pb(A[i]-i);
    }
    
    vector<int> helper3;
    for(int i = 0; i < n; i++){
        helper3.pb(-A[i]+i);
    }
    
    vector<int> helper4;
    for(int i = 0; i < n; i++){
        helper4.pb(-A[i]-i);
    }
    
    sort(all(helper1));
    sort(all(helper2));
    sort(all(helper3));
    sort(all(helper4));
    
    int answer = helper1[n-1]-helper1[0];
    answer = max(helper2[n-1]-helper2[0], answer);
    answer = max(helper3[n-1]-helper3[0], answer);
    answer = max(helper4[n-1]-helper4[0], answer);
    
    return answer;
}

