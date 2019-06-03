/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = 0;
    ListNode *temp = A;
    ListNode *LastNode = NULL;
    while(temp != NULL){
        LastNode = temp;
        temp = temp->next;
        n++;
    }
    
    if(n == B || (B > n && (B%n) == 0)) return A;
    
    ListNode *prev = NULL;
    temp = A;
    for(int i = 0; i < n-(B%n); i++){
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    if(temp != LastNode) LastNode->next = A;
    else temp->next = A;
    return temp;
}
