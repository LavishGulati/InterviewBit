/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *prev = A;
    ListNode *head = A->next;
    while(head != NULL){
        if(head->val == prev->val){
            head = head->next;
            prev->next = head;
        }
        else{
            head = head->next;
            prev = prev->next;
        }
    }
    return A;
}
