typedef long long ll;

int Solution::books(vector<int> &A, int B) {
    ll n = A.size();
    if(n < B) return -1;
    
    ll TotalPages = 0;
    for(ll i = 0; i < n; i++) TotalPages += A[i];
    
    ll si = 0;
    ll ei = TotalPages;
    ll mid, pages, i, num, answer;
    while(si <= ei){
        mid = (si+ei)/2;
        
        num = 0; pages = 0;
        for(i = 0; i < n; i++){
            if(A[i] > mid){
                num = INT_MAX;
                break;
            }
            
            if(pages+A[i] <= mid) pages += A[i];
            else{
                num++;
                pages = 0;
                i--;
            }
        }
        
        
        if(num < B){
            answer = mid;
            ei = mid-1;
        }
        else si = mid+1;
    }
    
    return answer;
}

