## 题目描述

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

## 解题思路
把两个数字num1和num2的相加，看作两部分，num1和num2不产生进位的相加产生新的数字n1(异或运算)，num1和num2只产生进位的结果n2(与运算)，然后n1和n2进行或运算就可以得到相加的结果。如果n1和n2相加还会产生进位，那么我们就继续再对n1和n2做同样的步骤，直到它们相加不产生进位为止。

## C++代码
```
class Solution {
public:
    int Add(int num1, int num2)
    {
        int carry = (num1 & num2) << 1;
        int non_carry = num1 ^ num2;

        while(carry & non_carry)
        {
            int temp1 = carry;
            int temp2 = non_carry;
            carry = (temp1 & temp2) << 1;
            non_carry = temp1 ^ temp2;
        }

        return carry | non_carry;
    }
};
```

## 易错点
记得在计算过程中用其他变量保存carry和non_carry，因为计算过程中，这两个变量的值会跟着改变。
