#define pb push_back

void MakeLetterCombinations(int id, string &A, vector<string> &output, string *helper, string temp){
    if(id == A.length()){
        output.pb(temp);
        return;
    }
    
    char c;
    for(int i = 0; i < helper[A[id]-'0'].length(); i++){
        c = helper[A[id]-'0'][i];
        MakeLetterCombinations(id+1, A, output, helper, temp+c);
    }
}

vector<string> Solution::letterCombinations(string A) {
    string *helper = new string[10];
    helper[0] = "0";
    helper[1] = "1";
    helper[2] = "abc";
    helper[3] = "def";
    helper[4] = "ghi";
    helper[5] = "jkl";
    helper[6] = "mno";
    helper[7] = "pqrs";
    helper[8] = "tuv";
    helper[9] = "wxyz";
    
    vector<string> output;
    MakeLetterCombinations(0, A, output, helper, "");
    return output;
}
