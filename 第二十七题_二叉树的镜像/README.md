## 题目描述

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

## 解题思路
先序遍历一颗树，并且在遍历的时候交换左右子节点。

## C++代码
```
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot) 
            return;
        
        swap(pRoot->left, pRoot->right);
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }

    void swap(TreeNode* &p1, TreeNode* &p2)
    {
        TreeNode *tmp;
        tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
};
```

## 易错点
记得swap函数传入一个指针的引用，不能只传入指针。
