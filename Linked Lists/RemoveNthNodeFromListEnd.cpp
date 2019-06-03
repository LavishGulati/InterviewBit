/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = 0;
    ListNode *temp = A;
    while(temp != NULL){
        temp = temp->next;
        n++;
    }
    
    if(B >= n){
        A = A->next;
    }
    else{
        temp = A;
        for(int i = 0; i < n-B-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    
    return A;
}
