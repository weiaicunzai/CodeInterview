## 题目描述

输入一个链表，输出该链表中倒数第k个结点。

## 解题思路
当然，最暴力的方法就是全部遍历完一遍链表，知道链表有多长，然后再第二次遍历链表，获得第k个
节点的长度。这种方法显然不是最快的方法。一种更优的方法，是我们用两个指针来计数，第一个指针
从链表头节点开始遍历，当移动了k-1次之后，第二个指针开始从头节点遍历，当第一个指针移动到链表
结尾的时候，我们第二个指针所指的节点就是倒数第k个节点。


## C++代码
```
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead)
            return nullptr;
        
        ListNode *cur = pListHead;
        ListNode *knode = nullptr;
        int count = 1;

        if(k == 1)
        {
            while(cur->next)
                cur = cur->next;
            return cur;
        }

        //cur->next, not cur 
        while(cur->next)
        {
            if(count == k - 1)
                knode = pListHead;
            
            //move knode to next, except for
            //the first ti
            //if(knode != pListHead && knode) //error
            if(count != k - 1 && knode)
                knode = knode->next;
            
            count++;
            cur = cur->next;
        }

        return knode;
    }
};
```

## 易错点
首先要考虑k=1的情况，因为k-1等于0，而我们的count是从1开始计数的，如果不进行额外处理，
将会死循环。对于k=1的情况，直接返回最后一个结点即可。

用count进行计数，统计```cur```指针走过了多少个节点(包括当前所指的节点)，当```count != k - 1```
时，第二个指针指向头节点。当```cur```指针来到链表的最后一个节点时停止。返回第二个指针。
