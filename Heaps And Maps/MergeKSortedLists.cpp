/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Compare
{
public:
    bool operator() (ListNode *ap, ListNode *bp)
    {
        return ap->val > bp->val;
    }
}; 

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size();
    
    ListNode *head, *temp;
    head = temp = NULL;
    
    priority_queue<ListNode *, vector<ListNode *>, Compare> pq;
    for(int i = 0; i < n; i++){
        if(A[i] != NULL) pq.push(A[i]);
    }
    
    ListNode *ap, *NewNode;
    while(!pq.empty()){
        ap = pq.top();
        
        NewNode = new ListNode(ap->val);
        if(head == NULL){
            head = temp = NewNode;
        }
        else{
            temp->next = NewNode;
            temp = temp->next;
        }
        
        pq.pop();
        if(ap->next != NULL){
            pq.push(ap->next);
        }
    }
    
    return head;
}
