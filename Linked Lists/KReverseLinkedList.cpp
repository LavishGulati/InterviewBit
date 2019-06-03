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
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode *prev, *sp, *ep, *bp, *temp;
    prev = NULL;
    sp = ep = A;
    bp = A->next;
    int num = 0;
    while(1){
        if(num < B-1){
            ep = bp;
            bp = bp->next;
            num++;
        }
        else{
            temp = ep;
            ReverseLL(sp, &temp);
            
            if(prev == NULL && bp == NULL){
                sp->next = NULL;
                A = ep;
                break;
            }
            else if(prev == NULL){
                A = ep;
                sp->next = bp;
                prev = sp;
                sp = ep = bp;
                bp = bp->next;
            }
            else if(bp == NULL){
                prev->next = ep;
                sp->next = NULL;
                break;
            }
            else{
                prev->next = ep;
                prev = sp;
                sp->next = bp;
                sp = ep = bp;
                bp = bp->next;
            }
            num = 0;
        }
    }
    
    return A;
}
