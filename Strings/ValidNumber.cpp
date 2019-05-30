int Solution::isNumber(const string A) {
    string helper = A;
    while(helper[helper.length()-1] == ' ') helper = helper.substr(0, helper.length()-1);
    
    int n = helper.length();
    bool IsE = false;
    bool IsDecimal = false;
    bool IsPos = helper[0] == '+' ? true : false;
    bool IsNeg = helper[0] == '-' ? true : false;
    bool IsStart = false;
    
    
    int i = 0;
    while(helper[i] == ' '){
        i++;
    }
    if(i == n) return 0;
    
    if(helper[n-1] == '.' || helper[n-1] == 'e' || helper[n-1] == '+' || helper[n-1] == '-') return 0;
    if((IsPos || IsNeg) && n == 1) return 0;
    
    for(; i < n; i++){
        if(i == 0){
            if(!IsPos && !IsNeg && !(helper[i] >= '0' && helper[i] <= '9') && helper[i] != '.') return 0;
            else continue;
        }
        
        if(helper[i] == '.'){
            if(IsDecimal || IsE) return 0;
            else{
                IsDecimal = true;
                if(helper[i+1] == 'e') return 0;
                continue;
            }
        }
        
        if(helper[i] == 'e'){
            if(IsE) return 0;
            else{
                IsE = true;
                if(helper[i+1] == '-' || helper[i+1] == '+') i++;
                continue;
            }
        }
        
        if(!(helper[i] >= '0' && helper[i] <= '9')) return 0;
    }
    
    return 1;
}

