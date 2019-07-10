typedef long long ll;
#define all(x) x.begin(), x.end()

vector<int> flag, parent, val;

string solve(int n){
    int p, q, i, total = 0;
    
    string output = "";
    queue<int> myq;
    int temp = 1%n;
    flag[temp] = 1;
    val[temp] = 1;
    myq.push(temp);
    
    while(1){
        temp = myq.front();
        myq.pop();
        p = temp;
        
        if(p == 0){
            p = 0;
            output += char(val[p]+'0');
            p = parent[p];
            while(p != 0){
                output += char(val[p]+'0');
                p = parent[p];
            }
            reverse(all(output));
            return output;
        }
        
        q = (p*10)%n;
        if(flag[q] == 0){
            myq.push(q);
            flag[q] = 1;
            parent[q] = p;
            val[q] = 0;
        }
        q++;
        if(q >= n) q -= n;
        if(flag[q] == 0){
            myq.push(q);
            flag[q] = 1;
            parent[q] = p;
            val[q] = 1;
        }
    }
}

string Solution::multiple(int A) {
    flag.clear();
    parent.clear();
    val.clear();
    flag.resize(A);
    val.resize(A);
    parent.resize(A);
    return solve(A);
}
