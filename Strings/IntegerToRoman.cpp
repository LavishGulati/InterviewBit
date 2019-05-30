string Solution::intToRoman(int A) {
    string input = to_string(A);
    int n = input.length();
    string output = "";
    int id = 0;
    string helper;
    string a, b, c;
    for(int i = n-1; i >= 0; i--){
        if(id == 0){
            a = "I"; b = "V"; c = "X";
        }
        else if(id == 1){
            a = "X"; b = "L"; c = "C";
        }
        else if(id == 2){
            a = "C"; b = "D"; c = "M";
        }
        else if(id == 3){
            a = "M";
        }
        
        if(input[i] <= '3'){
            for(int j = 0; j < input[i]-'0'; j++) output = a+output;
        }
        else if(input[i] == '4') output = a+b+output;
        else if(input[i] <= '8'){
            helper = b;
            for(int j = 0; j < input[i]-'5'; j++) helper += a;
            output = helper+output;
        }
        else output = a+c+output;
        
        id++;
    }
    
    return output;
}

