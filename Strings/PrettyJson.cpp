#define pb push_back

vector<string> Solution::prettyJSON(string A) {
    int n = A.length();
    
    vector<string> output;
    if(A[0] == '[') output.pb("[");
    else if(A[0] == '{') output.pb("{");
    string answer = "\t";
    int tab = 1;
    bool IsValid;
    for(int i = 1; i < n; i++){
        if(A[i] == '[' || A[i] == '{'){
            if(A[i-1] != ',' && A[i-1] != '[' && A[i-1] != '{') output.pb(answer);
            answer = "";
            for(int j = 0; j < tab; j++) answer += "\t";
            answer += A[i];
            output.pb(answer);
            tab++;
            answer = "";
            for(int j = 0; j < tab; j++) answer += "\t";
        }
        else if(A[i] == ']' || A[i] == '}'){
            output.pb(answer);
            tab--;
            answer = "";
            for(int j = 0; j < tab; j++) answer += "\t";
            answer += A[i];
        }
        else if(A[i] == ','){
            answer += A[i];
            output.pb(answer);
            answer = "";
            for(int j = 0; j < tab; j++) answer += "\t";
        }
        else{
            answer += A[i];
        }
    }
    
    output.pb(answer);
    return output;
}
