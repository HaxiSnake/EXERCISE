
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL || pHead->next==NULL || pHead->next->next==NULL)
            return NULL;
        ListNode* fast=pHead->next->next;
        ListNode* slow=pHead->next;
        while(fast!=slow){
            if(fast!=NULL && slow!=NULL && fast->next!=NULL ){
                fast=fast->next->next;
                slow=slow->next;
            }else{
                return NULL;
            }
        }
        fast=pHead;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
        
    }
};
