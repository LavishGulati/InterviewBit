#define pb push_back

int Solution::removeElement(vector<int> &A, int B) {
    int i = 0, j = 0, temp;
    while(i < A.size()){
        if(A[i] != B){
            A[j] = A[i];
            j++;
        }
        i++;
    }
    A.erase(A.begin()+j, A.end());
    return A.size();
}
