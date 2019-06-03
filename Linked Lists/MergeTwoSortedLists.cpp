/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head = NULL;
    ListNode *temp = NULL;
    ListNode *ap = A;
    ListNode *bp = B;
    ListNode *NewNode;
    while(ap != NULL && bp != NULL){
        if(ap->val < bp->val){
            NewNode = new ListNode(ap->val);
            ap = ap->next;
        }
        else{
            NewNode = new ListNode(bp->val);
            bp = bp->next;
        }
        
        if(head == NULL){
            head = NewNode;
            temp = NewNode;
        }
        else{
            temp->next = NewNode;
            temp = temp->next;
        }
    }
    
    while(ap != NULL){
        NewNode = new ListNode(ap->val);
        ap = ap->next;
        if(head == NULL){
            head = NewNode;
            temp = NewNode;
        }
        else{
            temp->next = NewNode;
            temp = temp->next;
        }
    }
    
    while(bp != NULL){
        NewNode = new ListNode(bp->val);
        bp = bp->next;
        if(head == NULL){
            head = NewNode;
            temp = NewNode;
        }
        else{
            temp->next = NewNode;
            temp = temp->next;
        }
    }
    
    return head;
}
