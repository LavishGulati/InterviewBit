/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
#define pb push_back
 
map<UndirectedGraphNode *, UndirectedGraphNode *> m;

void dfs(UndirectedGraphNode *node, UndirectedGraphNode *head){
    m[node] = head;
    
    UndirectedGraphNode *temp, *v;
    for(int i = 0; i < node->neighbors.size(); i++){
        temp = node->neighbors[i];
        
        if(m.find(temp) == m.end()){
            v = new UndirectedGraphNode(temp->label);
            head->neighbors.pb(v);
            dfs(temp, v);
        }
        else head->neighbors.pb(m[temp]);
    }
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
    dfs(node, head);
    return head;
}
