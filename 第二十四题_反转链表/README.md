## 题目描述

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

## 解题思路


## C++代码
```
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead)
            return nullptr;
        if(!pHead->next)
            return pHead;
        
        ListNode *pre = nullptr;
        ListNode *cur = pHead;

        while(cur->next)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        cur->next = pre;
        return cur;
    }
};
```

## 易错点
无。只要记得考虑空链表和只有一个节点的链表就行了。
