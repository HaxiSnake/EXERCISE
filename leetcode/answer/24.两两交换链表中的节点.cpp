/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* vhead=new ListNode(-1);
        vhead->next=head;
        ListNode *prenode=vhead;
        while(prenode->next!=NULL && prenode->next->next!=NULL){
            ListNode *front=prenode->next;
            ListNode *back=front->next;
            prenode->next=back;
            front->next=back->next;
            back->next=front;
            prenode=prenode->next->next;
        }
        return vhead->next;
    }
};