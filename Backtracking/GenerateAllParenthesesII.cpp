#define pb push_back

vector<string> output;

void GenerateParentheses(int NumOpen, int A, string s){
    if(A == 0){
        for(int i = 0; i < NumOpen; i++){
            s += ')';
        }
        output.pb(s);
        return;
    }
    
    GenerateParentheses(NumOpen+1, A-1, s+'(');
    
    if(NumOpen > 0){
        GenerateParentheses(NumOpen-1, A, s+')');
    }
}

vector<string> Solution::generateParenthesis(int A) {
    output.clear();
    GenerateParentheses(0, A, "");
    return output;
}
