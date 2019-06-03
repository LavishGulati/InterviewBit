/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
bool ReorderList(ListNode **sp, ListNode *ep){
    if(ep == NULL) return true;
    
    if(!ReorderList(sp, ep->next)) return false;;
    
    if((*sp) == ep){
        (*sp)->next = NULL;
        return false;
    }
    else if((*sp)->next == ep){
        (*sp)->next->next = NULL;
        return false;
    }
    
    ep->next = (*sp)->next;
    (*sp)->next = ep;
    (*sp) = (ep->next);
    return true;
}
 
ListNode* Solution::reorderList(ListNode* A) {
    ListNode *sp = A;
    ReorderList(&sp, A);
    return A;
}
