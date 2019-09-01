import os
os.chdir(os.path.dirname(__file__))
title="27.反转链表"
content="输入一个链表，反转链表后，输出新链表的表头。"
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



