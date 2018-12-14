## 题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

## 解题思路
其实思路是比较简单的，就是从外向里顺时针遍历。但是问题就是边界条件很多，必须要搞清楚才行。
我们可以把遍历整个矩阵的过程，看成依次遍历矩阵的一圈，每一圈遍历的操作是一样的。但是需要注意的
是，在快遍历完成时，有4种情况。
1，矩阵只剩一行
2，矩阵只剩一列
3，矩阵只剩两列
4，矩阵只剩两行
这四种就是递归遍历结束的边界条件。

## C++代码
```
class Solution {
public:
    vector<int> result;

    vector<int> printMatrix(vector<vector<int> > matrix) {
        print_circle(matrix, 0, 0, matrix[0].size()- 1, matrix.size() - 1);
        return result;
    }

    void print_row(vector<vector<int> > &m, int row, int l_col, int r_col) 
    {
        for(int i = l_col; i <= r_col; i++)
            result.push_back(m[row][i]);
    }

    void print_col(vector<vector<int> > &m, int col, int top_row, int bot_row)
    {
        for(int i = top_row; i <= bot_row; i++)
            result.push_back(m[i][col]);
    }

    void print_two_line(vector<vector<int> > &m, int tl_col, int tl_row, int br_col, int br_row)
    {
        for(int i = tl_col; i <= br_col; i++)
            result.push_back(m[tl_row][i]);
        for(int i = br_col; i >= tl_col; i--)
            result.push_back(m[br_row][i]);
    }

    void print_circle(vector<vector<int> > &m, int tl_col, int tl_row, int br_col, int br_row)
    {
        if(tl_col > br_col)
            return;
        if(tl_row == br_row)
        {
            print_row(m, tl_row, tl_col, br_col);
            return;
        }

        if(tl_col == br_col)
        {
            print_col(m, tl_col, tl_row, br_row);
            return;
        }
        if(tl_row == br_row - 1)
        {
            print_two_line(m, tl_col, tl_row, br_col, br_row);
            return;
        }

        // add top edge
        for(int col = tl_col; col <= br_col; col++)
            result.push_back(m[tl_row][col]);
        
        //add right edge
        for(int row = tl_row + 1; row <= br_row; row++)
        {
            result.push_back(m[row][br_col]);
        }
        
        //add bottom edge
        for(int col = br_col - 1; col >= tl_col; col--)
            result.push_back(m[br_row][col]);
        
        //add left edge
        for(int row = br_row - 1; row >= tl_row + 1; row--)
            result.push_back(m[row][tl_col]);
        
        print_circle(m, tl_col + 1, tl_row + 1, br_col - 1, br_row - 1);
    }
};
```

## 易错点
各种边界条件，该加一的时候加一，该减去一的时候减去一，等等，一定不要弄混了。
另外，只剩两行和只剩两列这种情况容易忽略掉，需要重视。