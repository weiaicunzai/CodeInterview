## 题目描述

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

## 解题思路
使用短路求值原理，&&就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算。
把(ans)当作替换if语句的功能


## C++代码
```
class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        sum && (sum += Sum_Solution(n - 1));
        return sum;
    }
};
```

## 易错点
