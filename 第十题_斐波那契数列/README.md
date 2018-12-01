## 题目描述

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

## 解题思路
首先，肯定不能使用递归的解法，因为会导致内存溢出。可以使用一个Bottom-Up的方法，n=0时，斐波那契
数是0，n=1时，斐波那契数是1，n=2时是0+1 = 2，所以我们在计算第n个数的时候，将前n-1个斐波那契数
组都计算出来，就可以得到结果了。

## C++代码
```

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        
        if(n == 1)
            return 1;
        
        int sum = 0;
        sum = 1 + 0;
        int sum1 = 0;
        int sum2 = 1;
        for(int i = 2; i <= n; i++)
        {
            sum = sum1 + sum2;
            sum1 = sum2;
            sum2 = sum;
        }
        
        return sum;
    }
};

```

## 易错点
注意斐波那契数组是前两个数的和，不是第i个数相加。