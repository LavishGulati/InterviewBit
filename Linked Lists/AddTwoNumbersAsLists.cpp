/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
bool RemoveTrailingZeros(ListNode *prev, ListNode *temp){
    if(temp == NULL) return true;
    
    if(!RemoveTrailingZeros(temp, temp->next)) return false;
    
    if(temp->val == 0){
        prev->next = NULL;
        return true;
    }
    else return false;
}
 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head = NULL, *temp;
    ListNode *ap = A;
    ListNode *bp = B;
    ListNode *NewNode;
    int carry = 0;
    while(ap != NULL || bp != NULL){
        if(ap != NULL && bp != NULL){
            NewNode = new ListNode((ap->val + bp->val + carry)%10);
        }
        else if(ap != NULL){
            NewNode = new ListNode((ap->val + carry)%10);
        }
        else if(bp != NULL){
            NewNode = new ListNode((bp->val + carry)%10);
        }
        
        if(head == NULL){
            head = NewNode;
            temp = head;
        }
        else{
            temp->next = NewNode;
            temp = temp->next;
        }
        
        if(ap != NULL && bp != NULL){
            carry = (ap->val + bp->val + carry)/10;
            ap = ap->next;
            bp = bp->next;
        }
        else if(ap != NULL){
            carry = (ap->val + carry)/10;
            ap = ap->next;
        }
        else if(bp != NULL){
            carry = (bp->val + carry)/10;
            bp = bp->next;
        }
    }
    
    NewNode = new ListNode(carry);
    if(head == NULL){
        head = NewNode;
        temp = head;
    }
    else{
        temp->next = NewNode;
        temp = temp->next;
    }
    
    RemoveTrailingZeros(NULL, head);
    return head;
}
