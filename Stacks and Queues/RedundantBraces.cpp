int Solution::braces(string A) {
    stack<char> s;
    int n = A.length(), m;
    string helper;
    bool IsValid;
    
    for(int i = 0; i < n; i++){
        if(s.empty()) s.push(A[i]);
        else if(A[i] == ')'){
            if(s.top() == '(') return 1;
            
            helper = "";
            while(s.top() != '('){
                helper += s.top();
                s.pop();
            }
            IsValid = false;
            for(int j = 0; j < helper.length(); j++){
                if(helper[j] == '+' || helper[j] == '-' || helper[j] == '/' || helper[j] == '*'){
                    IsValid = true;
                    break;
                }
            }
            if(!IsValid) return 1;
            s.pop();
        }
        else s.push(A[i]);
    }
    
    
    return 0;
}
