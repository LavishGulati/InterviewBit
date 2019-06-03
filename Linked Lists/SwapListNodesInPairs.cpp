/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *prev, *sp, *ep, *bp;
    prev = NULL;
    sp = A;
    bp = A->next;
    while(1){
        if(sp == NULL) break;
        ep = sp->next;
        if(ep == NULL) break;
        bp = ep->next;
        
        if(prev == NULL && bp == NULL){
            A = ep;
            ep->next = sp;
            sp->next = NULL;
            break;
        }
        else if(prev == NULL){
            A = ep;
            ep->next = sp;
            sp->next = bp;
            prev = sp;
            sp = ep = bp;
            bp = ep->next;
        }
        else if(bp == NULL){
            prev->next = ep;
            ep->next = sp;
            sp->next = NULL;
            break;
        }
        else{
            prev->next = ep;
            ep->next = sp;
            sp->next = bp;
            prev = sp;
            sp = ep = bp;
            bp = ep->next;
        }
    }
    return A;
}
