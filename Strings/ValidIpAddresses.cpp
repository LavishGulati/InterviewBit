#define pb push_back
typedef long long ll;

void generateIpAddresses(string A, int id, int sum, vector<string> &output, vector<int> &helper){
    if(id == A.length() && sum < 3) return;
    
    if(sum == 3){
        if(helper[sum-1] == A.length()-1) return;
        
        ll x = stoll(A.substr(helper[2]+1));
        
        if(x == 0 && A.length()-helper[2]-1 > 1) return;
        else if(x > 0 && A[helper[sum-1]+1] == '0') return;
        
        if(x >= 0 && x <= 255){
            string answer = A.substr(0, helper[0]+1)+"."+A.substr(helper[0]+1, helper[1]-helper[0])+".";
            answer += A.substr(helper[1]+1, helper[2]-helper[1])+"."+A.substr(helper[2]+1);
            output.pb(answer);
        }
        return;    
    }
    
    ll x;
    bool check = true;
    if(sum == 0){
        x = stoll(A.substr(0, id+1));
        if(x == 0 && id+1 > 1) check = false;
        else if(x > 0 && A[0] == '0') check = false;
    }
    else{
        x = stoll(A.substr(helper[sum-1]+1, id-helper[sum-1]));
        if(x == 0 & id-helper[sum-1] > 1) check = false;
        else if(x > 0 && A[helper[sum-1]+1] == '0') check = false;
    }
    
    if(check && x >= 0 && x <= 255){
        helper.pb(id);
        generateIpAddresses(A, id+1, sum+1, output, helper);
        helper.pop_back();
    }
    
    generateIpAddresses(A, id+1, sum, output, helper);
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> output;
    vector<int> helper;
    if(A.length() <= 12) generateIpAddresses(A, 0, 0, output, helper);
    return output;
}

