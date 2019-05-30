#define all(x) x.begin(), x.end()

string Solution::longestPalindrome(string A) {
    int n = A.length();
    int si, MaxLength = 0, j, k;
    for(int i = 0; i < n; i++){
        j = 0;
        while(i-j >= 0 && i+j < n){
            if(A[i-j] == A[i+j]) j++;
            else break;
        }
        
        if(MaxLength < 2*j-1){
            MaxLength = 2*j-1;
            si = i-j+1;
        }
        
        if(i > 0){
            j = i-1;
            k = i;
            while(j >= 0 && k < n){
                if(A[j] == A[k]){
                    j--;
                    k++;
                }
                else break;
            }
            if(MaxLength < k-j-1){
                MaxLength = k-j-1;
                si = j+1;
            }
        }
        
        if(i < n-1){
            j = i;
            k = i+1;
            while(j >= 0 && k < n){
                if(A[j] == A[k]){
                    j--;
                    k++;
                }
                else break;
            }
            if(MaxLength < k-j-1){
                MaxLength = k-j-1;
                si = j+1;
            }
        }
    }
    
    return A.substr(si, MaxLength);
}
