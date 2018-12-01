## 题目描述

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

## 解题思路
此题和青蛙跳的解题思路很相似。首先，我们分析对于第n个台阶，我们第一步有几种条法。很明显，我们第一步有n种跳法。
第一步跳1个台阶，2个台阶，3个台阶，。。。。。一直到n个台阶。对于每一种条法，我们可以得到如下的分析：
```
f(n) = f(n - 1) + f(n - 2) + ..... + f(2) + f(1)
```
其中```f(n - 2) + ..... + f(2) + f(1)```等于```f(n-1)```。则上式可以化简为：
```
f(n) = 2 * f(n - 1)
```
所以，f(n)是一个公比为2的等比数列

## C++代码
```
class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        
        int number2 = 2;

        int result;
        for(int i = 3; i <= number; i++)
        {
            result = number2 * 2;
            number2 = result;
        }
        return result;
    }
};

```
## 易错点
