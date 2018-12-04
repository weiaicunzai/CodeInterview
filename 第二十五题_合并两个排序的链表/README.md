## 题目描述

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

## 解题思路
本题的思路非常简单，就是一直比较两个链表节点的大小，分别创建两个指针p1和p2，当p1的节点比p2小的
时候，将p1添加进新的链表中，再将p1指向改链表中的下一个节点，之后再继续比较p1和p2。直到p1或者p2
至少有一个为空时跳出循环。如果循环结束时，p1为空，则将p2剩余的节点全部添加到新的节点中，如果p2为
空，做类似的操作。

## C++代码
```
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        ListNode *result;
        if(p1->val <= p2->val)
        {
           result = p1; 
           p1 = p1->next;
        }
        else
        {
            result = p2;
            p2 = p2->next;
        }

        ListNode *cur = result;
        while(p1 && p2)
        {
            if(p1->val <= p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
        }
        if(p1 && !p2)
            cur->next = p1;
        else if(!p1 && p2)
            cur->next = p2;

        return result;

    }
};
```

## 易错点

注意是从小到大的顺序，而不是从大到小。所以是p1->val <= p2->val。