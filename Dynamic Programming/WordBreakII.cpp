#define pb push_back
#define all(x) x.begin(), x.end()

vector<string> output;

void word(string &A, int id, string answer, set<string> *helper){
    if(id == A.length()){
        output.pb(answer);
        return;
    }
    
    
    
    for(string s : helper[A[id]-'a']){
        if(id+s.length()-1 < A.length() && A.substr(id, s.length()) == s){
            if(id == 0){
                word(A, id+s.length(), answer+s, helper);
            }
            else{
                word(A, id+s.length(), answer+' '+s, helper);
            }
        }
    }
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    output.clear();
    
    set<string> *helper = new set<string>[26];
    for(int i = 0; i < B.size(); i++){
        helper[B[i][0]-'a'].insert(B[i]);
    }
    
    string answer = "";
    word(A, 0, answer, helper);
    return output;
}
