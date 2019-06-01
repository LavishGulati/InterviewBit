#define all(x) x.begin(), x.end()
typedef long long ll;

int Solution::threeSumClosest(vector<int> &A, int B) {
    ll n = A.size();
    sort(all(A));
    ll answer = INT_MAX;
    ll i = 0, j, k, x;
    while(i < n){
        x = ll(B)-ll(A[i]);
        j = i+1; k = n-1;
        while(j < k){
            if(abs(answer-ll(B)) > abs(x-ll(A[j])-ll(A[k]))){
                answer = ll(A[i])+ll(A[j])+ll(A[k]);
            };
            if(answer == B) return B;
            if(A[j]+A[k] > x) k--;
            else j++;
        }
        i++;
    }
    return answer;
}
