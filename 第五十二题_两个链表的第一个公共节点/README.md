## 题目描述

输入两个链表，找出它们的第一个公共结点。

## 解题思路
我们分别遍历两个链表，获得两个链表的长度，之后算出两个链表的差值l。找到最长的那个链表，
让最长的链表的头节点走l个节点，此时再让两个两个节点同时开始走，两个节点相遇的第一个相同
的节点就是共同的节点。

## C++代码
```
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1 = 0;
        int l2 = 0;

        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        while(p1)
        {
            p1 = p1->next;
            l1++;
        }
        while(p2)
        {
            p2 = p2->next;
            l2++;
        }

        p1 = pHead1;
        p2 = pHead2;

        if(l1 > l2)
            for(int i = 0; i < l1 - l2; i++)
                p1 = p1->next;
        if(l1 < l2)
            for(int i = 0; i < l2 - l1; i++)
                p2 = p2->next;
        
        while(p1 && p2)
        {
            if(p1 == p2)
                break;
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};
```

## 易错点
区分q和!q