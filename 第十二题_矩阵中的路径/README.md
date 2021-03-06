## 题目描述

请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

## 解题思路
该题可以使用回溯法进行求解，需要把之前遍历过的字符设置为'\0'。

## C++代码
```
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int row = 0; row < rows; row++)
            for(int col = 0; col < cols; col++)
                if(found(matrix, row, col, str, rows, cols))
                    return true;
        
        return false;

    }
    bool found(char* m, int row, int col, char *str, int rows, int cols)
    {
        if(row < 0 || row > rows)
            return false;
        
        if(col < 0 || col > cols)
            return false;
        
        if(*str != *(m + row * cols + col))
            return false;
        
        if(*str == '\0')
            return true;
        
        if(*(m + row * cols + col) == '\0')
            return false;
        
        bool result;
        char temp = *(m + row * cols + col);
        *(m + row * cols + col) = '\0';

        result = found(m, row + 1, col, str + 1, rows, cols) ||
                 found(m, row - 1, col, str + 1, rows, cols) ||
                 found(m, row, col + 1, str + 1, rows, cols) ||
                 found(m, row, col - 1, str + 1, rows, cols);

        *(m + row * cols + col) = temp;

        return result;
    }
};


```

## 易错点
最不容易想到的点就是循环结束的条件，并不像原始的二分查找算法，low和high指针最终会指向同一个元素，
在这个题中，low和high永远无法指向同一个元素。也就是说，数组元素个数最少是2个。

对于
[0,1,1,1,1] -> [1,1,1,0,1]这种情况，low=mid-high，无法用二分查判断出mid在哪个部分，所以只能
逐个查找。