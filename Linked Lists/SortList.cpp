/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* MergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head = A;
    
    ListNode *ap = A, *bp = B, *prev = NULL;
    ListNode *temp;
    while(ap != NULL && bp != NULL){
        if(ap->val <= bp->val){
            prev = ap;
            ap = ap->next;
        }
        else{
            temp = bp;
            bp = bp->next;
            if(prev != NULL){
                prev->next = temp;
                temp->next = ap;
                prev = temp;
            }
            else{
                temp->next = ap;
                head = temp;
                prev = temp;
            }
        }
    }
    
    if(bp != NULL){
        prev->next = bp;
    }
    return head;
}

ListNode *MergeSort(ListNode *head, ListNode *tail, int n){
    if(n == 1) return head;
    if(n == 2){
        if(head->val <= tail->val) return head;
        else{
            tail->next = head;
            head->next = NULL;
            return tail;
        }
    }
    
    ListNode *midp = NULL;
    ListNode *temp = head;
    for(int i = 0; i < n/2; i++){
        midp = temp;
        temp = temp->next;
    }
    temp = midp->next;
    midp->next = NULL;
    
    ListNode *ap = MergeSort(head, midp, n/2);
    ListNode *bp = MergeSort(temp, tail, n-(n/2));
    
    ListNode *answer = MergeTwoLists(ap, bp);
    return answer;
}
 
ListNode* Solution::sortList(ListNode* A) {
    ListNode *head = A;
    ListNode *prev = NULL;
    ListNode *tail = A;
    int n = 0;
    while(tail != NULL){
        prev = tail;
        tail = tail->next;
        n++;
    }
    return MergeSort(head, prev, n);
}
