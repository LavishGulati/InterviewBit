typedef long long ll;

string Solution::fractionToDecimal(int A, int B) {
    ll a = A;
    ll b = B;
    
    string answer = "";
    if(a < 0 && b > 0) answer += '-';
    else if(a > 0 && b < 0) answer += '-';

    a = abs(a);
    b = abs(b);
    
    answer += to_string(a/b);
    a %= b;
    if(a == 0) return answer;
    
    answer += '.';
    int num = 0;
    char c;
    map<int, int> m;
    while(a != 0){
        if(m.find(a) != m.end()){
            return answer.substr(0, answer.length()-num+m[a]-1)+'('+answer.substr(answer.length()-num+m[a]-1)+')';
        }
        
        c = (a*10)/b + '0';
        answer += c;
        num++;
        m[a] = num;
        a = (a*10)%b;
    }
    
    return answer;
}
