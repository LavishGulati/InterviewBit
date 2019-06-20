/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    A->next = NULL;
    TreeLinkNode *prev = NULL, *temp = A;
    TreeLinkNode *ap;
    while(1){
        prev = NULL;
        while(temp != NULL){
            if(temp->left != NULL){
                prev = temp->left;
                break;
            }
            else if(temp->right != NULL){
                prev = temp->right;
                break;
            }
            temp = temp->next;
        }
        
        if(prev == NULL) break;
        
        ap = prev;
        if(ap == temp->left){
            if(temp->right != NULL){
                ap->next = temp->right;
                ap = temp->right;
            }
        }
        
        temp = temp->next;
        while(temp != NULL){
            if(temp->left != NULL){
                ap->next = temp->left;
                ap = temp->left;
            }
            
            if(temp->right != NULL){
                ap->next = temp->right;
                ap = temp->right;
            }
            
            temp = temp->next;
        }
        
        temp = prev;
    }
}
