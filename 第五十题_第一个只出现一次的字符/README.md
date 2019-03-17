## 题目描述

在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

## 解题思路
先遍历一边数组，用map保存所有元素出现的次数。之后再次遍历数组，找到第一个出现次数为1的元素，并返回下标，如果没有就返回-1。


## C++代码
```
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> stats;
        for(auto iter = str.begin(); iter != str.end(); iter++)
            stats[*iter]++;
        
        for(auto iter = str.begin(); iter != str.end(); iter++)
            if(stats[*iter] == 1)
                return distance(str.begin(), iter);
        
        return -1;
    }
};
```

## 易错点