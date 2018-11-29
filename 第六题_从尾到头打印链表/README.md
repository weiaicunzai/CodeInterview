## 题目描述

输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

## 解题思路
此题可以使用链表逆序做，但是为了避免修改链表，我们将使别的方法来实现。
思路非常简单，首先对链表进行遍历，将结果保存在一个栈中，再对栈中的结果
依次出栈就行了。


## C++代码
```
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(!head) return vector<int>();

        //保存到栈内
        stack<ListNode *> temp;
        while(head)
        {
            temp.push(head);
            head = head->next;
        }

        vector<int> result;
        
        //出栈
        while(!temp.empty())
        {
            ListNode *h = temp.top();
            result.push_back(h->val);
            temp.pop();
        }

        return result;
    }
};
```

## 易错点
不能写出如下代码：
```
for(int i = 0; i < temp.size(); i++)
{
    ListNode *h = temp.top();
    result.push_back(h->val);
    temp.pop();
}
```
因为temp.size()的大小会随着每次for循环变化，不是一个定值。