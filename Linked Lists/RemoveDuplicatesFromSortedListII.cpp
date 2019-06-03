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
    ListNode *head = NULL;
    ListNode *temp = A->next;

    int num;
    while(temp != NULL){
        num = 0;
        while(temp != NULL && temp->val == prev->val){
            temp = temp->next;
            num++;
        }
        if(num > 0){
            if(temp == NULL && head == NULL){
                A = NULL;
            }
            else if(temp == NULL){
                head->next = NULL;
            }
            else if(head == NULL){
                A = temp;
                prev = temp;
                temp = temp->next;
            }
            else{
                head->next = temp;
                prev = temp;
                temp = temp->next;
            }
        }
        else if(temp != NULL){
            head = prev;
            prev = temp;
            temp = temp->next;
        }
    }
    
    return A;
}
