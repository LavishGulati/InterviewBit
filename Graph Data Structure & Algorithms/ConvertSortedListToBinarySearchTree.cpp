/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

TreeNode *solve(ListNode *head, ListNode *tail){
    if(head == NULL || tail == NULL) return NULL;
    if(head == tail){
        TreeNode *NewNode = new TreeNode(head->val);
        return NewNode;
    }
    
    ListNode *temp = head, *prev, *next;
    int num = 1;
    while(temp != tail){
        num++;
        temp = temp->next;
    }
    
    num /= 2;
    temp = head;
    prev = NULL;
    next = head->next;
    while(num--){
        prev = temp;
        temp = next;
        next = next->next;
    }
    if(prev != NULL) prev->next = NULL;
    if(temp != NULL) temp->next = NULL;
    
    TreeNode *NewNode = new TreeNode(temp->val);
    TreeNode *left = solve(head, prev);
    TreeNode *right = solve(next, tail);
    NewNode->left = left;
    NewNode->right = right;
    return NewNode;
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    ListNode *head = A;
    ListNode *tail = A;
    while(tail->next != NULL) tail = tail->next;
    return solve(head, tail);
}
