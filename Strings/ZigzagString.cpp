string Solution::convert(string A, int B) {
    int n = A.length();
    
    if(B == 1) return A;
    if(n == 1) return A;
    
    string output = "";
    int x = 2*B-2;
    int y = 0;
    int num = 0;
    int i = 0;
    int turn = 0;
    while(output.length() < n){
        if(i >= n){
            num++;
            i = num;
            turn = 0;
            x -= 2;
            y += 2;
            continue;
        }
        
        if(turn == 0){
            turn ^= 1;
            if(x == 0) continue;
            
            output += A[i];
            i += x;
        }
        else{
            turn ^= 1;
            if(y == 0) continue;
            
            output += A[i];
            i += y;
        }
    }
    
    return output;
}
