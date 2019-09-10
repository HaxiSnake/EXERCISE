import os
os.chdir(os.path.dirname(__file__))
title="34.合并两个排序的链表"
content="输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。"
isstar=False
code="""
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL) return pHead2;
        if(pHead2==NULL) return pHead1;
        ListNode* head;
        if( pHead1->val<=pHead2->val ){
            head = pHead1;
            pHead1 = pHead1->next;
        }else{
            head = pHead2;
            pHead2 = pHead2->next;
        }
        ListNode* cur = head;
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val<=pHead2->val){
                cur->next=pHead1;
                cur=cur->next;
                pHead1 = pHead1->next;
            }else{
                cur->next=pHead2;
                cur=cur->next;
                pHead2 = pHead2->next;
            }
        }
        if(pHead1==NULL){
            cur->next = pHead2;
        }else{
            cur->next = pHead1;
        }
        return head;
    }
};
"""
md_list="* [{0}](#{0}) [解答](./{0}.cpp)".format(title)
essay="## {0}\n\n{1}\n".format(title,content)
if(isstar):
    md_list+=" &star;"

print(md_list)
print(essay)

with open("{0}.cpp".format(title),'w') as out:
    out.writelines(code)
out.close()



