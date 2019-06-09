class node{
    public:
    
    int key;
    node *next;
    node *prev;

    node(int key){
        this->key = key;
        next = prev = NULL;
    }
};

node *head;
node *tail;
int num;
int cap;
map<int, int> m;

LRUCache::LRUCache(int capacity) {
    num = 0;
    cap = capacity;
    head = NULL;
    tail = NULL;
    m.clear();
}

int LRUCache::get(int key) {
    if(m.find(key) == m.end()) return -1;
    
    node *temp = head;
    while(temp->key != key){
        temp = temp->next;
    }
    
    node *ap = temp->prev;
    node *bp = temp->next;
    
    if(bp != NULL){
        if(ap == NULL){
            head = bp;
            head->prev = NULL;
        }
        else{
            ap->next = bp;
            bp->prev = ap;
        }
        
        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        tail = tail->next;
    }
    
    return m[key];
}

void LRUCache::set(int key, int value) {
    if(m.find(key) != m.end()){
        m[key] = value;
    }
    else if(num == 0){
        node *NewNode = new node(key);
        head = NewNode;
        m[key] = value;
        tail = head;
        num++;
    }
    else if(num < cap){
        node *NewNode = new node(key);
        tail->next = NewNode;
        NewNode->prev = tail;
        tail = tail->next;
        m[key] = value;
        num++;
    }
    else{
        m.erase(head->key);
        head->key = key;
        m[key] = value;
    }
    
    get(key);
}
