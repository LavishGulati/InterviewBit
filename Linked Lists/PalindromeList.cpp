/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
bool CheckPalindrome(ListNode *temp, ListNode **head, int &x){
    if(temp == NULL){
        return true;
    }
    
    if(!CheckPalindrome(temp->next, head, x)) return false;
    
    if((*head)->val != temp->val){
        x = 0;
        return false;
    }
    else (*head) = (*head)->next;
    return true;
}
 
int Solution::lPalin(ListNode* A) {
    ListNode *head = A;
    ListNode *temp = A;
    int helper = 2;
    if(CheckPalindrome(temp, &head, helper)){
        return 1;
    }
    else return 0;
}
