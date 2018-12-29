## 题目描述

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

## 解题思路

使用两个stack存储数据，一个stack存储原始数据，另一个stack存储在push后所有栈中数据的最小值。

## C++代码
```
class Solution {

    stack<int> s1;
    stack<int> s2;

    int s1_min = INT_MAX;

public:
    void push(int value) {
        if(value < s1_min)
        {
            s2.push(value);
            s1_min = value;
        }
        else
        {
            s2.push(s1_min);
        }

        s1.push(value);
    }
    void pop() {
         s1.pop();
         s2.pop();
    }
    int top() {
        return s1.top(); 
    }
    int min() {
        return s2.top(); 
    }
};
```

## 易错点

