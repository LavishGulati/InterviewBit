typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

int Solution::maxPoints(vector<int> &X, vector<int> &Y) {
    map< double, set<int> > m;
    int n = X.size();
    
    if(n == 1) return 1;
    
    double slope;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(X[i]-X[j] == 0) slope = INT_MAX;
            else slope = abs((double(Y[i])-double(Y[j]))/(double(X[i])-double(X[j])));
            
            m[slope].insert(i);
            m[slope].insert(j);
        }
    }
    
    // int MaxSize = 0;
    // for(auto i = m.begin(); i != m.end(); i++){
    //     MaxSize = max(MaxSize, int((i->s).size()));
    // }
    
    map<double, int> helper;
    double c;
    int MaxSize = 0;
    for(auto i = m.begin(); i != m.end(); i++){
        slope = i->f;
        for(auto j = (i->s).begin(); j != (i->s).end(); j++){
            if(slope == 0) c = Y[*j];
            else if(slope != INT_MAX) c = X[*j] - Y[*j]/slope;
            else c = X[*j];
            helper[c]++;
            // if(slope == 0) cout << c << " ";
        }
        // if(slope == 0) cout << endl;
        for(auto j = helper.begin(); j != helper.end(); j++){
            MaxSize = max(MaxSize, j->s);
        }
        helper.clear();
        // if(slope == 0) cout << slope << " " << MaxSize << endl;
    }
    
    return MaxSize;
}
