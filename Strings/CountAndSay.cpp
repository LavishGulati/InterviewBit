string Solution::countAndSay(int A) {
    string output = "1";
    string helper;
    int freq, j;
    for(int i = 1; i < A; i++){
        freq = 1;
        helper = "";
        j = 1;
        for(; j < output.size(); j++){
            if(output[j] == output[j-1]) freq++;
            else{
                helper += '0'+freq;
                helper += output[j-1];
                freq = 1;
            }
        }
        helper += '0'+freq;
        helper += output[j-1];
        
        output = helper;
    }
    
    return output;
}

