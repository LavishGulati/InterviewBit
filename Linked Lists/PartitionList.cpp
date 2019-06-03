/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *head, *ep;
    head = NULL;
    ep = A;
    while(ep->val < B){
        head = ep;
        ep = ep->next;
    }
    
    ListNode *ap, *bp;
    ap = ep->next;
    bp = ep;
    while(ap != NULL){
        if(ap->val < B){
            if(head == NULL){
                bp->next = ap->next;
                ap->next = ep;
                A = ap;
                head = ap;
                ap = bp->next;
            }
            else{
                head->next = ap;
                bp->next = ap->next;
                ap->next = ep;
                head = head->next;
                ap = bp->next;
            }
        }
        else{
            bp = ap;
            ap = ap->next;
        }
    }
    
    return A;
}
