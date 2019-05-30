string half(string A){
    string output;
    int carry = 0, a, b;
    char c;
        
    output = "";
    for(int i = 0; i < A.length(); i++){
        a = A[i]-'0';
        c = '0'+((carry*10+a)/2);
        carry = (carry*10+a)%2;
        output += c;
    }
    while(output[0] == '0') output = output.substr(1);
    return output;
}

string add(string A, string B){
    int a = A.length();
    int b = B.length();
    int n = max(a, b);
    
    for(int i = 0; i < n-a; i++) A = '0'+A;
    for(int i = 0; i < n-b; i++) B = '0'+B;
    
    int carry = 0, x, y;
    char c;
    string output = "";
    for(int i = n-1; i >= 0; i--){
        x = A[i]-'0';
        y = B[i]-'0';
        c = '0'+((carry+x+y)%10);
        carry = (carry+x+y)/10;
        output = c+output;
    }
    c = '0'+carry;
    output = c+output;
    while(output[0] == '0') output = output.substr(1);
    return output;
}

string ReduceBy1(string A){
    int n = A.length();
    int i = n-1;
    while(A[i] == '0'){
        A[i] = '9';
        i--;
    }
    A[i] -= 1;
    return A;
}

string Solution::multiply(string A, string B) {
    if(B == "0" || A == "0") return "0";
    if(B == "1") return A;
    if(A == "1") return B;
    
    if(A.length() < B.length()){
        string temp = A;
        A = B;
        B = temp;
    }
    
    if((B[B.length()-1]-'0')%2 == 0){
        string B_2 = half(B);
        string y = multiply(A, B_2);
        string answer = add(y, y);
        
        if(answer == "") return "0";
        else return answer;
    }
    else{
        string B_2 = half(ReduceBy1(B));
        string y = multiply(A, B_2);
        y = add(y, y);
        string answer = add(A, y);
        
        if(answer == "") return "0";
        else return answer;
    }
}
