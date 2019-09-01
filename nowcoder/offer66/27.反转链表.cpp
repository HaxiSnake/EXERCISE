
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL) return NULL;
        if(pHead->next==NULL) return pHead;
        ListNode* head=NULL;
        ListNode* cur=pHead;
        while(cur!=NULL && cur->next!=NULL){
            ListNode* tmp = cur->next;
            cur->next=head;
            ListNode* tmpcur = tmp->next;
            tmp->next=cur;
            cur=tmpcur;
            head=tmp;
        }
        if(cur==NULL){
            return head;
        }else{
            cur->next=head;
            head=cur;
        }
        return head;
    }
};
