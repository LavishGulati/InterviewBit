#define pb push_back

string Solution::simplifyPath(string A) {
    stack<string> s;
    vector<string> input;
    int i = 1;
    for(int j = 1; j < A.length(); j++){
        if(A[j] == '/'){
            if(i == j){
                i++;
            }
            else{
                input.pb(A.substr(i, j-i));
                i = j+1;
            }
        }
    }
    if(i != A.length()){
        input.pb(A.substr(i, A.length()-i));
    }
    
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ".."){
            if(s.size() > 0) s.pop();
            else s.push("");
        }
        else if(input[i] == "."){
            if(s.size() == 0) s.push("");
        }
        else s.push(input[i]); 
    }
    
    string output = "";
    while(!s.empty()){
        output = "/"+s.top()+output;
        s.pop();
    }
    while(output.size() > 1 && output[1] == '/') output = output.substr(1);
    return output;
}
