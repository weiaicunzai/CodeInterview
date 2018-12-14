## 题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

## 解题思路

声明一个新的数组，遍历原来的数组，如果是奇数就添加进新的数组里，然后再次遍历数组，再将偶数添加进新的数组里。
时间复杂度是o(n)

## C++代码
```
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() <= 1)
            return;
        
        vector<int> result;
        for(auto x : array)
            if(x % 2)
                result.push_back(x);
            
        for(auto x : array)
            if(!(x % 2))
                result.push_back(x);
        
        array = result;
    }
};
```

## 易错点

