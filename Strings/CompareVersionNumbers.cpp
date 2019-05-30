#define pb push_back

bool compare(string a, string b){
    while(a[0] == '0') a = a.substr(1);
    while(b[0] == '0') b = b.substr(1);
    
    if(a.length() < b.length()) return true;
    else if(a.length() > b.length()) return false;
    
    for(int i = 0; i < a.length(); i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
    return false;
}

int Solution::compareVersion(string A, string B) {
    vector<string> a, b;
    int i = 0;
    for(int j = 0; j < A.length(); j++){
        if(A[j] == '.'){
            a.pb(A.substr(i, j-i));
            i = j+1;
        }
    }
    a.pb(A.substr(i, A.length()-i));
    
    i = 0;
    for(int j = 0; j < B.length(); j++){
        if(B[j] == '.'){
            b.pb(B.substr(i, j-i));
            i = j+1;
        }
    }
    b.pb(B.substr(i, B.length()-i));
    
    for(i = 0; i < min(a.size(), b.size()); i++){
        if(compare(a[i], b[i])) return -1;
        else if(compare(b[i], a[i])) return 1;
    }
    
    if(a.size() < b.size()){
        for(; i < b.size(); i++){
            if(b[i] != "0") return -1;
        }
        return 0;
    }
    else if(a.size() > b.size()){
        for(; i < a.size(); i++){
            if(a[i] != "0") return 1;
        }
        return 0;
    }
    else return 0;
}
