## 题目描述

输入两个链表，找出它们的第一个公共结点。

## 解题思路
我们分别遍历两个链表，获得两个链表的长度，之后算出两个链表的差值l。找到最长的那个链表，
让最长的链表的头节点走l个节点，此时再让两个两个节点同时开始走，两个节点相遇的第一个相同
的节点就是共同的节点。

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

        //if (data[mid] == k && mid == data.size() - 1)
        //    return mid;

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
区分q和!q