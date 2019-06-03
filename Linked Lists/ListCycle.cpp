/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *ap, *bp;
    ap = bp = A;
    while(1){
        ap = ap->next;
        if(ap == NULL) return NULL;
        bp = bp->next;
        if(bp == NULL) return NULL;
        bp = bp->next;
        if(bp == NULL) return NULL;
        
        if(ap == bp) break;
    }
    
    set<ListNode *> s;
    s.insert(A);
    ap = A;
    while(1){
        if(s.find(ap->next) != s.end()) return ap->next;
        else{
            ap = ap->next;
            s.insert(ap);
        }
    }
}
