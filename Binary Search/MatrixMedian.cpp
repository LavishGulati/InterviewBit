int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int si = INT_MAX;
    for(int i = 0; i < n; i++){
        si = min(si, A[i][0]);
    }
    int ei = INT_MIN;
    for(int i = 0; i < n; i++){
        ei = max(ei, A[i][m-1]);
    }
    
    int mid, si2, ei2, mid2, NumBigger, NumSmaller, NumEqual, x, y;
    while(si <= ei){
        mid = (si+ei)/2;
        NumBigger = 0, NumSmaller = 0;
        for(int i = 0; i < n; i++){
            si2 = 0;
            ei2 = m-1;
            while(si2 <= ei2){
                mid2 = (si2+ei2)/2;
                if(A[i][mid2] < mid) si2 = mid2+1;
                else if(A[i][mid2] > mid) ei2 = mid2-1;
                else break;
            }
            
            if(A[i][mid2] < mid){
                NumBigger += m-1-mid2;
                NumSmaller += mid2+1;
            }
            else if(A[i][mid2] > mid){
                NumBigger += m-mid2;
                NumSmaller += mid2;
            }
            else{
                int j, k;
                j = k = mid2;
                while(j >= 0 && A[i][j] == A[i][mid2]) j--;
                while(k < m && A[i][k] == A[i][mid2]) k++;
                NumSmaller += j+1;
                NumBigger += m-k;
            }
        }
        
        NumEqual = n*m-NumBigger-NumSmaller;
        
        if(NumEqual > 0 && (NumEqual+NumSmaller-NumBigger-1)%2 == 0){
           y = (NumEqual+NumSmaller-NumBigger-1)/2;
           x = NumEqual-y-1;
           if(y >= 0 && x >= 0) return mid;
        }
        
        if(NumBigger > NumSmaller){
            si = mid+1;
        }
        else if(NumBigger < NumSmaller){
            ei = mid-1;
        }
    }
}

