#define pb push_back

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> output;
    if(A.size() == 0) return output;
    
    int total = 0, NumWords = 0, filled, j, NumSpaces, x, k, i;
    string answer;
    for(i = 0; i < A.size(); i++){
        if(total+NumWords+A[i].length() > B){
            filled = 0;
            for(j = i-NumWords; j < i; j++) filled += A[j].length();
            answer = "";
            if(NumWords == 1) NumSpaces = B-filled+1;
            else if((B-filled)%(NumWords-1) != 0){
                NumSpaces = int(ceil((double(B-filled))/(double(NumWords-1))));
            }
            else NumSpaces = (B-filled)/(NumWords-1) + 1;
            x = 0;
            
            for(j = i-NumWords; j < i-1; j++){
                answer += A[j];
                for(k = 0; k < NumSpaces-1; k++) answer += ' ';
                if(x < (B-filled)%(NumWords-1)) answer += ' ';
                x++;
            }
            answer += A[j];
            while(answer.size() < B) answer += ' ';
            output.pb(answer);
            
            total = A[i].length();
            NumWords = 1;
        }
        else{
            total += A[i].length();
            NumWords++;
        }
    }
    
    answer = "";
    for(j = i-NumWords; j < i-1; j++){
        answer += A[j]+' ';
    }
    answer += A[j];
    while(answer.size() < B) answer += ' ';
    output.pb(answer);
    
    return output;
}
