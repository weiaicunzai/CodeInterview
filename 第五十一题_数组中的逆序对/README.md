## 题目描述

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

## 解题思路
使用归并排序进行计算，每次统计出数组左半部分中，比右半部分多的数字对。时间复杂度是o(nlogn)

## C++代码
```
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()) 
            return 0;
        
        return merge_sort(data, 0, data.size() - 1) % 1000000007;
    }

    long long merge_sort(vector<int>& data, int low, int hight)
    {
        if(hight == low)
            return 0;
        
        int mid = low + (hight - low) / 2;
        long long count_left = merge_sort(data, low, mid);
        long long count_right = merge_sort(data, mid + 1, hight);

        auto it_left = data.begin() + mid;
        auto it_right = data.begin() + hight;
        vector<int> temp(hight - low + 1);
        long long count = 0;
        auto it = temp.end() - 1;

        while(distance(data.begin() + low, it_left) >= 0 && distance(data.begin() + mid + 1, it_right) >= 0)
        {
            if(*it_left > *it_right)
            {
                *it-- = *it_left--;
                count += distance(data.begin() + mid, it_right);
            }
            else
                *it-- = *it_right--;
        }

        while(distance(data.begin() + low, it_left) >= 0)
            *it-- = *it_left--;
        while(distance(data.begin() + mid + 1, it_right) >= 0)
            *it-- = *it_right--;
        
        //copy temp back to original data;
        copy_n(temp.begin(), temp.size(), data.begin() + low);

        return count_right + count_left + count;
    }
};
```

## 易错点
基本上就是实现一个归并排序，和单纯的归并排序不同的地方就是每次都要统计出左半部分中比
右半部分多的数子对，也就是逆序对。注意，此时数组左半部分和右半部分都已经是一个有序的数组
了，只是整个数组还不是有序的。因此，统计逆序对的时候，不能简单的count++。
如下面的例子：

12, 54, 1, 33

左半边12,54, 右半边1,33。此时两个指针分别指向54,33，选出最大的数字54,放入临时数组，
左边的指针指向12,由于54大于33,必然也大于1,因此我们要用以下的代码更新逆序对的个数：
count += distance(data.begin() + mid, it_right);