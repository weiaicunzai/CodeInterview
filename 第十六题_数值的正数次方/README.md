## 题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

## 解题思路

最简单直白的方式，就是exponent是多少，就乘上多少个base，就能得到正确的结果了。需要
注意的可能就是exponent为0或者为负数的时候该如何处理了。

## C++代码
```
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 1)
            return 0;
        
        double result = 1;
        for(int i = 0; i < abs(exponent); i++)
            result *= base;

        if(exponent < 0)
            return 1 / result;
        
        return result;
    }
};
```

## 易错点
没有考虑指数为0或者负数的情况。