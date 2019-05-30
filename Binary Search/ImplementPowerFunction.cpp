typedef long long ll;

int Solution::pow(int x, int n, int d) {
    if(n == 0) return (1+d)%d;
    if(n == 1) return (x+d)%d;
    
    if(n%2 == 0){
        ll y = pow(x, n/2, d);
        return (((y*y)%d)+d)%d;
    }
    else{
        ll y = pow(x, (n-1)/2, d);
        return (((x*((y*y)%d))%d)+d)%d;
    }
}

