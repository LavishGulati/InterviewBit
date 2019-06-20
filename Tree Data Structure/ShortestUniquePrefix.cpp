#define pb push_back

class node{
    public:
    char val;
    vector<node *> children;
    int freq;
    
    node(char x){
        val = x;
        for(int i = 0; i < 26; i++){
            children.pb(NULL);
        }
        freq = 0;
    }
};

string answer;

void insert(node *root, string &s, int id){
    if(id == s.length()) return;
    
    if(root->children[s[id]-'a'] == NULL){
        root->children[s[id]-'a'] = new node(s[id]);
    }
    
    (root->children[s[id]-'a']->freq)++;
    insert(root->children[s[id]-'a'], s, id+1);
}

void ShortestUniquePrefix(node *root, string &s, int id){
    if(root->children[s[id]-'a']->freq == 1){
        answer += s[id];
        return;
    }
    
    answer += s[id];
    ShortestUniquePrefix(root->children[s[id]-'a'], s, id+1);
}

vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    vector<string> output;
    node *root = new node('.');
    
    for(int i = 0; i < n; i++){
        insert(root, A[i], 0);
    }
    
    
    for(int i = 0; i < n; i++){
        answer = "";
        ShortestUniquePrefix(root, A[i], 0);
        output.pb(answer);
    }
    return output;
}
