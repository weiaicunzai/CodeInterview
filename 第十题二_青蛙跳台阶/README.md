## 题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

## 解题思路
此题是可以被转化为求斐波那契数列的，当青蛙要跳到第n个台阶的时候，他的第一次跳有两种情况，第一种情况是第一次跳就跳一个
台阶，第二种情况是第一次跳两个台阶。第一次跳一个台阶的跳法有多少种呢？由于此时还剩下n-1个台阶，则还剩下f(n-1)种跳法。
而对于一次跳两个台阶的情况，我们有f(n-2)种情况。也就是说f(n) = f(n-1) + f(n-2)。

## C++代码
```
class Solution {
public:
    int jumpFloor(int number) {
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        
        int number1 = 1;
        int number2 = 2;
        int result;
        for(int i = 3; i <= number; i++)
        {
            result = number1 + number2;
            number1 = number2;
            number2 = result;
        }

        return result;
    }
};
```

## 易错点
