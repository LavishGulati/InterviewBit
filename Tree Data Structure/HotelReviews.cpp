typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

class node{
    public:
    char val;
    vector<node *> children;
    bool IsLeaf;
    
    node(char c){
        val = c;
        IsLeaf = false;
        for(int i = 0; i < 26; i++){
            children.pb(NULL);
        }
    }
};

void insert(string &s, int id, node *root){
    if(root->children[s[id]-'a'] == NULL) root->children[s[id]-'a'] = new node(s[id]);
    
    if(id < s.length()-1) insert(s, id+1, root->children[s[id]-'a']);
    else root->children[s[id]-'a']->IsLeaf = true;
}

bool find(string &s, int id, node *root){
    if(root->children[s[id]-'a'] == NULL) return false;
    
    if(id < s.length()-1) return find(s, id+1, root->children[s[id]-'a']);
    else{
        return root->children[s[id]-'a']->IsLeaf;
    }
}

bool compare(pii a, pii b){
    if(a.f > b.f) return true;
    else if(a.f == b.f){
        return a.s < b.s;
    }
    else return false;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    node *root = new node('.');
    
    int i = 0;
    string s;
    for(int j = 0; j < A.length(); j++){
        if(A[j] == '_'){
            s = A.substr(i, j-i);
            insert(s, 0, root);
            i = j+1;
        }
    }
    s = A.substr(i, A.length()-i);
    insert(s, 0, root);
    
    vector<pii> helper;
    int value;
    for(int i = 0; i < B.size(); i++){
        int j = 0;
        value = 0;
        for(int k = 0; k < B[i].length(); k++){
            if(B[i][k] == '_'){
                s = B[i].substr(j, k-j); 
                if(find(s, 0, root)) value++;
                j = k+1;
            }
        }
        s = B[i].substr(j, B[i].length()-j);
        if(find(s, 0, root)) value++;
        
        helper.pb(mp(value, i));
    }
    
    sort(all(helper), compare);
    vector<int> output;
    for(int i = 0; i < helper.size(); i++){
        output.pb(helper[i].s);
    }
    return output;
}
