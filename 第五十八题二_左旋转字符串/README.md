## 题目描述

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

## 解题思路
YX = (XT YT)T ,T为旋转的意思。将字符串分为k之前的部分和k之后的部分两部分。

## C++代码
```

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty())
            return str;
        int k = n;
        while(k > n)
            k %= str.size();
        
        int y = str.size() - k;
        int x = k;

        for(int i = 0; i < x / 2; i++) swap(str[i], str[x - i - 1]);
        for(int i = 0; i < y / 2; i++) swap(str[i + x], str[x + y - i - 1]);
        for(int i = 0; i < str.size() / 2; i++) swap(str[i], str[x + y - 1 - i]);

        return str;
    }
};
```

## 易错点
左旋应该是左边为k个，右边为str.size() - k个，不能相反。
