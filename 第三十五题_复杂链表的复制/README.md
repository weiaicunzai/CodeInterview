## 题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

## 解题思路

这道题的思路，就不讲n平方复杂度的解法了，比较暴力。将一个时间复杂度为n的解法。总共分为三步：

1. 首先，我们在原链表的每个节点的next指针指向的地方，创建一个值和原来一样的节点。
如：
原链表： ```a->b```
创建后: ```a->A->b->B```
2. 设置新链表的random指针。原链表中每个节点的random指针的next，就是新链表对应节点的random的指针，利用这个属性，可以得到新链表中所有random指针指向的节点。

3. 将2个链表分开。由于原链表每个元素后面就是一个新链表的节点，我们需要将两个链表分开。每隔一个节点就是相同的元素，按照这个规律，是可以很容易分开的。

## C++代码
```
#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        create_nodes(pHead);
        set_random(pHead);
        return split_nodes(pHead);
    }

    RandomListNode *split_nodes(RandomListNode *pHead)
    {
        if(!pHead)
            return pHead;

        RandomListNode *new_head = pHead->next;
        RandomListNode *new_node = pHead->next;
        RandomListNode *old_node = pHead;
        while(old_node && new_node->next)
        {
            old_node->next = old_node->next->next; 
            new_node->next = new_node->next->next; 
            
            old_node = old_node->next;
            new_node = new_node->next;
        }
        old_node ->next = nullptr;

        return new_head;
    }

    //set new nodes´s random pointer
    void set_random(RandomListNode* pHead)
    {
        while(pHead)
        {
            if(pHead->random)
                pHead->next->random = pHead->random->next;
            
            pHead = pHead->next->next;
        }
    }

    //create a cloned list node after each original nodes
    void create_nodes(RandomListNode *pHead)
    {
        while(pHead) 
        {
            RandomListNode *temp = new RandomListNode(pHead->label);
            temp->next = pHead->next; 
            pHead->next = temp;
            pHead = temp->next;
        }
    }
};
```

## 易错点
可能是oj的bug，oj判断，只要返回的新链表中，有一个节点的和旧链表中的节点一样，就判断返回为空。由于分开链表的时候，旧链表的最后一个节点的next值没有赋值为空，而是指向新链表的最后一个元素，则会被oj判断为空，需要将旧链表的最后一个节点的next指针赋值为空才行。


