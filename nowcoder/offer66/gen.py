import os
os.chdir(os.path.dirname(__file__))
title="14.两个链表的第一个公共结点"
content="输入两个链表，找出它们的第一个公共结点。"
isstar=True
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1=pHead1,*p2=pHead2;
        while(p1!=p2){
            p1=p1==NULL?pHead1:p1->next;
            p2=p2==NULL?pHead2:p2->next;
        }
        return p1;
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



