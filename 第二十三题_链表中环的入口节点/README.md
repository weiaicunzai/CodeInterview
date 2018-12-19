## 题目描述

给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

## 解题思路
先判断两个链表中是否有一个环，就是使用两个指针，一个一次移动一步，另一个一次移动两步。
如果最后两个指针相遇，则必定有一个环，否则就没有环。
左神说过一个思路，就是一个快指针，一个慢指针

## C++代码
```
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead || !pHead -> next) return nullptr;
        ListNode* p = pHead,*q = p;
        /* 第一趟*/
        while(q -> next)
        {
            p = p -> next;
            q = q -> next -> next;
            if(p == q) break;
        }
        /* 第二趟*/
        q = pHead;
        while(p != q)
        {
            p = p -> next;
            q = q -> next;
        }
        return p;
    }
};
```

## 易错点
