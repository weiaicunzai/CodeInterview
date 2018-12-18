## 题目描述

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

## 解题思路

使用一个比较简单的思路去做。在不修改数组的情况下，我们使用一个最大堆来存储所有最小的k个元素。首先将原始数组
中的前k个数字放进最大堆中，此时堆中最大的数就是堆顶元素。我们将继续遍历原始数组中剩余的元素，依次和最大堆的
堆顶元素进行比较，因此如果数组元素比堆顶元素小，则删除堆顶元素，把数组元素插入到堆中。

## C++代码
```
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size())
            return vector<int>();
        priority_queue<int> pq;

        for(int i = 0; i < input.size(); i++)
        {
            if(i < k)
            {
                pq.push(input[i]);
                continue;
            } 
            if(input[i] < pq.top())
            {
                pq.pop();
                pq.push(input[i]);
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
```

## 易错点
1，考虑k > 数组长度的情况
2, 考虑k <= 0 的情况。