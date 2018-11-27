## 题目描述

在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。

## 解题思路
首先，最简单的肯定就是暴力搜索，一个一个查找，但是会超时，所以不可取。一个比较好的思路是
从矩阵右上角开始遍历，如果最右边一列的第一个元素大于target，说明该列不可能有target，
直接从从左到右数第二列开始遍历，以此类推。如果某一列的第一个元素小于target，则说明
target可能在此列，开始遍历该列。如果遍历完后该列不存在target，则继续遍历该列左边的列。

## C++代码
```
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //边界检查
        if (array.empty())
            return false;

        //从右上角开始遍历
        for (int col = array[0].size() - 1; col >= 0; col--)
        {
            //每一列第一个值如果大于target，则target肯定不在此列
            if(array[0][col] > target)
                continue;
            
            for(int row = 0; row < array.size(); row++)
            {
                if(target == array[row][col])
                    return true;
                
                //如果某一列的某个元素比target小，就继续往下找
                else if(target > array[row][col])
                    continue;
            }
        }

        //没有找到，返回false
        return false;
    }
};
```

## 易错点
如果某一列未找到target，不代表该矩阵中不存在target，target可能存在在该列左边的列中。
```
for(int row = 0; row < array.size(); row++)
{
    if(target == array[row][col])
        return true;
            
        //如果某一列的某个元素比target小，就继续往下找
    else if(target > array[row][col])
        continue;
    
    else
        return false; //wrong 
}
```