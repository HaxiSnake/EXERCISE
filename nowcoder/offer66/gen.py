import os
os.chdir(os.path.dirname(__file__))
title="18.链表中环的入口节点"
content="给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。"
isstar=True
code="""
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



