## 题目描述

统计一个数字在排序数组中出现的次数。

## 解题思路
最简单的方法，就是遍历数组，然后统计出每个数字出现的次数。但是这种方式的时间复杂度是O(n)，还有
一种时间复杂度是O(logn)的算法。由于是一个已经排序的数组，我们只要知道第一个k出现的下标和最后一个
k出现的下标，就可以计算出数字出现的次数了。那么，第一次出现k的下标和第二次出现k的下标如何求解呢？
我们可以利用二分查找来获得。在查找k的情况下使用二分查找是一个很简单的算法，没有什么难度，但是判断
是否是第一个k或者第二个k，我们需要加一个额外的判断条件。当我们用二分查找法查找到k的时候，如果k之前
的一个数还是k，则说明我们这次找到的k并不是第一次出现的k，继续用二分法查找，直到找到的k前面的数字
不再是k为止。

## C++代码
```
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int left = get_first_k(data, k, 0, data.size() - 1);
        int right = get_last_k(data, k , 0, data.size() - 1);
        if(left == -1 || right == -1)
            return 0;
        
        return right - left + 1;
    }

    int get_last_k(const vector<int> &data, int k, int low, int high)
    {
        if(low > high)
            return -1;
        
        int mid = (low + high) / 2;

        if(data[mid] == k && mid == data.size() - 1)
            return mid;
        
        int index;

        if(data[mid] < k)
            index = get_last_k(data, k, mid + 1, high);
        
        if(data[mid] > k)
            index = get_last_k(data, k, low, mid - 1);
        
        if(data[mid] == k)
        {
            if(data[mid + 1] == k)
                index = get_last_k(data, k, mid + 1, high);
            else
                index = mid;
        }

        return index;
    }
    int get_first_k(const vector<int> &data, int k, int low, int high)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (data[mid] == k && mid == 0)
            return mid;

        int index;

        if (data[mid] < k)
            index = get_first_k(data, k, mid + 1, high);
        if (data[mid] > k)
            index = get_first_k(data, k, low, mid - 1);
        if (data[mid] == k)
        {
            if (data[mid - 1] == k)
                index = get_first_k(data, k, low, mid - 1);
            else
                index = mid;
        }

        return index;
    }
};
```

## 易错点
一些边界条件需要搞清楚。
返回式right - left + 1，不要忘记+1。