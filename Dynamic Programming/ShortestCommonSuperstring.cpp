typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back

int **dp;
int answer;

int calculate(string &a, string &b){
    int i;
    for(i = min(b.length(), a.length()); i > 0; i--){
        if(a.substr(a.length()-i) == b.substr(0, i)){
            break;
        }
    }
    
    return b.length()-i;
}

void superstring(int id, int n, vector<string> &A, vector<int> &helper, bool *IsTaken){
    if(id == n){
        int length = A[helper[0]].length(), x;
        for(int i = 1; i < n; i++){
            if(dp[helper[i-1]][helper[i]] != -1){
                x = dp[helper[i-1]][helper[i]];
            }
            else{
                x = calculate(A[helper[i-1]], A[helper[i]]);
                dp[helper[i-1]][helper[i]] = x;
            }
            length += x;
        }
        answer = min(answer, length);
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!IsTaken[i]){
            IsTaken[i] = true;
            helper.pb(i);
            superstring(id+1, n, A, helper, IsTaken);
            helper.pop_back();
            IsTaken[i] = false;
        }
    }
}

int Solution::solve(vector<string> &A) {
    int n = A.size();
    
    dp = new int *[n];
    for(int i = 0; i < n; i++){
        dp[i] = new int[n];
        for(int j = 0; j < n; j++) dp[i][j] = -1;
    }
    answer = INT_MAX;
    
    vector<int> helper;
    bool *IsTaken = new bool[n];
    for(int i = 0; i < n; i++) IsTaken[i] = false;
    superstring(0, n, A, helper, IsTaken);
    return answer;
}
