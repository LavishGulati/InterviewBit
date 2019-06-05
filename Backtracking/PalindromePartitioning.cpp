#define pb push_back

vector< vector<string> > output;

bool IsPalindrome(string &s){
    int n = s.length();
    for(int i = 0; i <= n/2; i++){
        if(s[i] != s[n-1-i]) return false;
    }
    
    return true;
}

void MakePartitions(int id, string s, string &A, vector<string> &helper){
    if(id >= A.length()){
        if(IsPalindrome(s)){
            helper.pb(s);
            output.pb(helper);
            helper.pop_back();
        }
        return;
    }
    
    if(IsPalindrome(s)){
        helper.pb(s);
        string temp = "";
        temp += A[id];
        MakePartitions(id+1, temp, A, helper);
        helper.pop_back();
    }
    
    MakePartitions(id+1, s+A[id], A, helper);
}

vector<vector<string> > Solution::partition(string A) {
    output.clear();
    vector<string> helper;
    string s = "";
    s += A[0];
    MakePartitions(1, s, A, helper);
    return output;
}
