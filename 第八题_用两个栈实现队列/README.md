## 题目描述

用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

## 解题思路
对于Push操作，只需要将所有元素都Push到stack1中就可以。
对于Pop操作，如果stack2不为空，则直接把stack2的栈顶元素出栈并返回就可以，如果
stack2为空，那么我们把stack1中的所有元素依次出栈，并推入stack2中，再将stack2
中的所有元素依次出栈就可以了。

注：最开始，我的思路是每次Pop操作后，将stack2中的所有元素再次出栈，再放入stack1中，
其实是没有必要的。因为stack2中的元素出栈顺序正好是最早进入stack1的元素先出栈，第二次
出栈的元素必然是stack2中仅次于栈顶的元素。

## C++代码
```
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {

        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int result = stack2.top();
        stack2.pop();
        return result;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

## 易错点

Pop操作中，不需要在每次Pop操作结尾都把stack2中的元素再次推入stack1中。