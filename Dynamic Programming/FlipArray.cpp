int MinSum;
int flips;

void FlipArray(int id, const vector<int> &A, int f, int sum){
    if(id == A.size()){
        if(abs(sum) < MinSum){
            MinSum = abs(sum);
            flips = f;
        }
        else if(abs(sum) == MinSum){
            flips = min(f, flips);
        }
        return;
    }
    
    FlipArray(id+1, A, f, sum+A[id]);
    FlipArray(id+1, A, f+1, sum-A[id]);
}

int Solution::solve(const vector<int> &A) {
    MinSum = INT_MAX;
    flips = INT_MAX;
    FlipArray(0, A, 0, 0);
    return flips;
}
