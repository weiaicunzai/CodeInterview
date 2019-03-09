## 题目描述

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

## 解题思路

平衡二叉树的左子树的元素都比右子树小，后序遍历后，树的根节点在序列的最后,左子树在序列的前面，左子树和根节点中间。如果右子树中出现了比根节点小的元素，则该序列不是一个平衡二叉树。我们需要继续递归的判断左子树和右子树是否都为平衡二叉树。跳出条件为该树为空。整体来说，思路并不难，就是细节太多。

## C++代码
```
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return judge(sequence, 0, sequence.size() - 1);
    }

    bool judge(vector<int> &sequence, int l, int r)
    {
        if(r < l)
            return false;
        if(r == l)
            return true;
        
        int last = sequence[r];
        int index = r;

        for(int i = 0 + l; i < r; i++)
        {
            //find the left tree and right tree
            if(sequence[i] > last)
            {
                index = i;
                break;
            }
        }

        //右子树有比last小的值
        for(int i = index; i < r; i++)
            if(sequence[i] < last)
                return false;

        bool left = true;
        //有左子树
        if (index - l)
            left = judge(sequence, l, index - 1);

        bool right = true;
        //有右子树
        if (r - index)
            right = judge(sequence, index, r - 1);

        return left && right;
    }
};
```
## 易错点
index变量初始值应该设为r。

递归查看右子树是否为平衡二叉树时，应该去掉根节点，传入r-1。

在判断右子树中是否含有比根节点小的元素时，我们可以分成两部分，第一个循环先找到左右子树的分界点。第二循环再查找右子树中是否有比根节点小的元素。
