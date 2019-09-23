
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* p = head;
        if(p==NULL) return { };
        vector<int> res;
        while(p!=NULL){
            res.push_back(p->val);
            p=p->next;
        }
        vector<int> v;
        for(int i=res.size()-1;i>=0;i--){
            v.push_back(res[i]);
        }
        return v;
    }
};
