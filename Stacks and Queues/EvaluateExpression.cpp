int Solution::evalRPN(vector<string> &A) {
    int n = A.size(), x, y;
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(A[i] == "+" || A[i] == "/" || A[i] == "*" || A[i] == "-"){
            y = s.top();
            s.pop();
            x = s.top();
            s.pop();
            if(A[i] == "+") s.push(x+y);
            else if(A[i] == "-") s.push(x-y);
            else if(A[i] == "*") s.push(x*y);
            else if(A[i] == "/") s.push(x/y);
        }
        else s.push(stoi(A[i]));
    }
    
    return s.top();
}
