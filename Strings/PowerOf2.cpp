int Solution::power(string A) {
    string output = A;
    string helper;
    int carry = 0, a, b;
    char c;
    
    if(output == "1") return 0;
    
    while(output != "1"){
        if((output[output.length()-1]-'0')%2 != 0){
            return 0;
        }
        
        helper = "";
        for(int i = 0; i < output.length(); i++){
            a = output[i]-'0';
            c = '0'+((carry*10+a)/2);
            carry = (carry*10+a)%2;
            helper += c;
        }
        while(helper[0] == '0') helper = helper.substr(1);
        output = helper;
    }
    
    return 1;
}
