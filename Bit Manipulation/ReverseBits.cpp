typedef unsigned int uint;

unsigned int Solution::reverse(unsigned int A) {
    uint power[32];
    power[0] = 1;
    for(uint i = 1; i < 32; i++){
        power[i] = power[i-1]*2;
    }
    
    uint answer = 0;
    for(uint i = 0; i < 32; i++){
        answer += power[31-i]*(A%2);
        A /= 2;
    }
    
    return answer;
}

