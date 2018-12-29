## 题目描述

输入一个链表，反转链表后，输出新链表的表头。

## 解题思路
使用两个指针```pre```和```cur```,```pre```指向所有已经被反转的节点的头节点，而```cur```
指向所有未被反转的节点的头节点。

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
