## 题目描述

输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

## 解题思路

两个指针，分别指向数组的第一个元素和最后一个元素，当两个指针指向的数字和小于sum的时候，我们将第一个指针往后移动，当两个指针指向的数字和大于sum的时候，我们将第二个指针往前移动，如果碰到两个指针指向的数字和相同，则代表找到了想要的数对。

## C++代码
```
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2)
            return array;
        auto min_num = array.begin();
        auto max_num = array.end() - 1;

        vector<int> res;
        while(min_num < max_num)
        {
            if(*min_num + *max_num == sum)
            {
                if(res.empty())
                {
                    res.push_back(*min_num);
                    res.push_back(*max_num);
                }
                else
                {
                    int num1 = *min_num * *max_num;
                    int num2 = res[0] * res[1];
                    if(num1 < num2)
                    {
                        res.clear();
                        res.push_back(*min_num);
                        res.push_back(*max_num);
                    }
                }
            }
            if(*min_num + *max_num < sum)
                min_num++;
            else
                max_num--;
        }

        return res;
    }
};

```

## 易错点
两个指针，同时向中间元素移动，有点类似快速排序。