/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void ReverseLL(ListNode *sp, ListNode **ep){
    if(sp == (*ep)) return;
    
    ReverseLL(sp->next, ep);
    
    (*ep)->next = sp;
    (*ep) = sp;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode *ap, *bp, *apPrev, *bpNext;
    ap = bp = A;
    apPrev = NULL;
    bpNext = A->next;
    
    for(int i = 0; i < B-1; i++){
        apPrev = ap;
        ap = ap->next;
    }
    
    for(int i = 0; i < C-1; i++){
        bp = bpNext;
        bpNext = bpNext->next;
    }
    
    ListNode *temp = bp;
    ReverseLL(ap, &temp);
    
    if(apPrev == NULL && bpNext == NULL){
        ap->next = NULL;
        A = bp;
    }
    else if(apPrev == NULL){
        A = bp;
        ap->next = bpNext;
    }
    else if(bpNext == NULL){
        apPrev->next = bp;
        ap->next = NULL;
    }
    else{
        apPrev->next = bp;
        ap->next = bpNext;
    }
    
    return A;
}
