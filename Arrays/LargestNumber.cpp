#define pb push_back
#define all(x) x.begin(), x.end()

bool compare(string a, string b){
    int x = stoi(a+b);
    int y = stoi(b+a);
    if(x < y) return true;
    else return false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> helper;
    int n = A.size();
    for(int i = 0; i < n; i++){
        helper.pb(to_string(A[i]));
    }
    
    sort(all(helper), compare);
    string output = "";
    for(int i = n-1; i >= 0; i--){
        output += helper[i];
    }
    while(output[0] == '0'){
        output = output.substr(1);
    }
    if(output == "") return "0";
    else return output;
}

