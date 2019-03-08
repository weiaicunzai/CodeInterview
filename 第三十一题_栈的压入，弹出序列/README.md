
## 题目描述

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

## 解题思路

本题有两个数组，一个数组代表进栈顺序pushV，另一个代表出栈顺序popV。解决这道题，我们可以声明一个辅助栈s。

1. 按照如栈顺序，把pushV中的元素依次push进辅助栈s中。

2. 每push进s一个元素，都需要和popV中的未出过栈的元素中的最早出栈的元素相比较，如果辅助栈的栈顶元素和popV中未出栈的元素的第一个元素相同，将该栈顶元素出栈，将popV中的该元素标记为已经出栈，然后指向popV中的下一个未出栈的元素。重复步骤2,直到不满足栈顶元素和popV中第一个未出栈元素相等的条件。此时如果pushV中还有元素未入栈，则跳至步骤1，否则跳至步骤3

3. s为空，则表明popV是合法出栈序列，否则为假。

## C++代码
```
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {

        if (pushV.empty() || popV.empty())  
            return false;
        
        stack<int> s;
        auto pop_iter = popV.begin();
        for(auto x : pushV)
        {
           s.push(x);
           while(pop_iter != popV.end() && s.top() == *pop_iter)
           {
                s.pop();
                pop_iter++;
           }
        }

        return s.empty();
    }
};
```

## 易错点
注意循环结束的条件，是popV没有遍历完，而且栈顶元素和popV中未出栈的第一个元素相同才行。


