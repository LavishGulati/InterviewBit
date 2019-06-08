/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *head, *temp, *ip, *jp;
    ip = head = temp = NULL;
    jp = A;
    while(jp != NULL){
        if(head == NULL){
            head = new RandomListNode(jp->label);
            temp = head;
            temp->random = jp;
        }
        else{
            temp->next = new RandomListNode(jp->label);
            temp = temp->next;
            temp->random = jp;
        }
        
        ip = jp;
        jp = jp->next;
        ip->next = temp;
    }
    
    temp = head;
    while(temp != NULL){
        if(temp->random->random != NULL) temp->random = temp->random->random->next;
        else temp->random = NULL;
        temp = temp->next;
    }
    
    return head;
}
