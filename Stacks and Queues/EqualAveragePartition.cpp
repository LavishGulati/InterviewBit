#define pb push_back
#define all(x) x.begin(), x.end()

vector<vector<vector<bool> > > dp;
vector<int> res;
vector<int> original;
int n;

bool possible(int id, int sum, int m){
    if(m == 0) return (sum == 0);
    if(id >= n) return false;
    
    if(dp[id][sum][m] == false) return false;
    
    if(sum >= original[id]){
        res.pb(original[id]);
        if(possible(id+1, sum-original[id], m-1)) return true;
        res.pop_back();
    }
    
    if(possible(id+1, sum, m)) return true;
    
    return dp[id][sum][m] = false;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    sort(all(A));
    original.clear();
    original = A;
    dp.clear();
    res.clear();
    
    int sum = 0;
    n = A.size();
    for(int i = 0; i < n; i++) sum += A[i];
    
    dp.resize(n, vector<vector<bool > >(sum+1, vector<bool>(n, true)));
    for(int i = 1; i < n; i++){
        if((sum*i)%n != 0) continue;
        
        int sum1 = (sum*i)/n;
        if(possible(0, sum1, i)){
            int j = 0, k = 0;
            vector<int> res1 = res;
            vector<int> res2;
            while(j < n || k < res.size()){
                if(k < res.size() && res[k] == A[j]){
                    j++;
                    k++;
                    continue;
                }
                res2.pb(A[j]);
                j++;
            }
            vector<vector<int> > ans;
            ans.pb(res1);
            ans.pb(res2);
            return ans;
        }
    }
    
    vector<vector<int> > ans;
    return ans;
}
