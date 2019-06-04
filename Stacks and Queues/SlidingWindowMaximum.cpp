#define pb push_back

class node{
    public:
    int val;
    node *next;
    node *prev;
    
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class list{
    node *head;
    node *tail;
    
    public:
    list(){
        head = tail = NULL;
    }
    
    bool empty(){
        if(head == NULL) return true;
        else return false;
    }
    
    int back(){
        return tail->val;
    }
    
    int front(){
        return head->val;
    }
    
    void PopBack(){
        node *temp = tail->prev;
        if(temp == NULL){
            delete(tail);
            head = tail = NULL;
            return;
        }
        
        delete(tail);
        temp->next = NULL;
        tail = temp;
    }
    
    void PopFront(){
        node *temp = head->next;
        if(temp == NULL){
            delete(head);
            head = tail = NULL;
            return;
        }
        
        delete(head);
        temp->prev = NULL;
        head = temp;
    }
    
    void InsertBack(int x){
        if(head == NULL){
            node *NewNode = new node(x);
            head = tail = NewNode;
            return;
        }
        
        node *NewNode = new node(x);
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = NewNode;
    }
};

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    list *NewList = new list;
    vector<int> output;
    int n = A.size();
    
    for(int i = 0; i < B; i++){
        while(!NewList->empty() && NewList->back() < A[i]){
            NewList->PopBack();
        }
        NewList->InsertBack(A[i]);
    }
    
    for(int i = 0; i < n-B+1; i++){
        output.pb(NewList->front());
        if(NewList->front() == A[i]){
            NewList->PopFront();
        }
        
        while(!NewList->empty() && NewList->back() < A[B+i]){
            NewList->PopBack();
        }
        NewList->InsertBack(A[B+i]);
    }
    
    return output;
}
