/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p = new ListNode(0);
    ListNode *q = p;
    
    int c = 0;
    while(l1 || l2){
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + c;
        c = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    
    if(c){
        p->next = new ListNode(1);
    }
    
    return q->next;
}
};