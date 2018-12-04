## 题目描述

我们可以用2x1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2x1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

## 解题思路

和青蛙跳台阶类似，也是可以转化为一个求斐波那契数列的问题

## C++代码
```
#include <iostream>

class Solution {
public:
    int rectCover(int number) {
        if(number == 0)
            return 0;
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
要考虑面积为0时的情况。