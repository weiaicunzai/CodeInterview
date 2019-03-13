## 题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

## 解题思路

将该数组看作两部分，出现次数超过一半的数字，和除了一半以外的数字，其实这道题可以抽象成这样，有一个数组，只有两个值，一个值出现次数超过一半，一个没有超过一半。我们使用一个整型计数count，如果某个数和前一个数不想等，count--，某个一个数和前一个数相等，count++，这样留下来的，必然是出现次数超过一半的数。

## C++代码
```
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int number = numbers[0];
        int count = 1;
        for(auto x : numbers)
        {
            if(count == 0)
                number = x;
            
            if(number != x)
                count--;
            else
                count++;
        }

        count = 0;
        for(auto x : numbers)
            if(x == number)
                count++;

        if(count > numbers.size() / 2)
            return number;
        return 0;
    }
};#include <vector>
#include <queue>

        return result;
    }
};
```

## 易错点
不要忘记，数组并不是一定会有一个数字出现超过一半次数，最后需要判断一下。