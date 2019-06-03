/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *head = A->next, *tail = A;
    ListNode *prev, *temp;
    while(head != NULL){
        prev = NULL;
        temp = A;
        while(temp != head && temp->val <= head->val){
            prev = temp;
            temp = temp->next;
        }
        if(temp != head){
            if(prev != NULL){
                tail->next = head->next;
                head->next = temp;
                prev->next = head;
                head = tail->next;
            }
            else{
                tail->next = head->next;
                head->next = temp;
                A = head;
                head = tail->next;
            }
        }  
        else{
            tail = head;
            head = head->next;
        }
    }
    
    return A;
}
