## 题目描述

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，
输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

## 解题思路
这道题的本质就是查找一个数组中的最小值，属于查找问题，但是从数组中第一个元素开始遍历，看哪个元素最小显然
不合适，时间复杂度为O(n)。因此可以考虑一些O(logn)的算法，比如二分查找。但是二分查找一般来说是用于已经排序
过的数组，但是仔细观察后可以发现，数组旋转过后，整个数组可以分成两个部分，数组最小值左边的部分大于最小值右边
的部分。使用二分法进行查找的时候，如果中间值大于数组中第一个数，则说明最小值在后半部分，如果中间值小于数组中
第一个值，则说明最小值在数组的左半部分。之后重复查找步骤，最后的结束条件就是当数组只有2个元素的时候，最小值
为第二个元素。因为第一个指针low将指向大于mid的元素的数组，而high将只想大于mid的元素的数组。最后不会出现low
和high都指向同一个元素的情况。

## C++代码
```
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        //if move the first 0 elements to the end
        if(rotateArray.front() < rotateArray.back())
            return rotateArray.front();
        
        return searchMin(rotateArray);
    }
    int iterate_through(const vector<int> &arr)
    {
            int min = 0;
            for(auto x : arr)
            {
                if(x < min)
                    min = x;
            }
            return min;
    }
    int searchMin(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        int mid = (low + high) / 2;
        while(arr[low] >= arr[high])
        {
            if((high - low) == 1)
            {
                mid = high;
                break;
            }
            
            if(arr[low] == arr[high] && arr[high] == arr[mid])
            {
                return iterate_through(arr);
            }

            if(arr[low] > arr[mid])
            {
                high = mid;
                mid = (low + high) / 2;
            }
            else if(arr[high] < arr[mid])
            {
                low = mid;
                mid = (low + high) / 2;
            }
        }
        return arr[mid];
    }
};
```

## 易错点
最不容易想到的点就是循环结束的条件，并不像原始的二分查找算法，low和high指针最终会指向同一个元素，
在这个题中，low和high永远无法指向同一个元素。也就是说，数组元素个数最少是2个。

对于
[0,1,1,1,1] -> [1,1,1,0,1]这种情况，low=mid-high，无法用二分查判断出mid在哪个部分，所以只能
逐个查找。