## 题目描述

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

## 解题思路
本题就是简单的中序遍历，因为是一个二叉搜索树，所以说，进行中序遍历的步骤也就是从小到大哦遍历数组
的步骤。

## C++代码
```
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int count = 0;
        return inOrder(pRoot, k, count);
    }

    TreeNode *inOrder(TreeNode *r, const int k, int &count)
    {
        if(!r)
            return nullptr;

        TreeNode *left = inOrder(r->left, k, count);

        count++;
        if(count == k)
            return r;
        
        TreeNode *right = inOrder(r->right, k, count);

        if(left)
            return left;
        if(right)
            return right;
        
        return nullptr;
    }
};
```

## 易错点
中序遍历时，只有在访问根节点的时候，count才需要加一，而且count要设置为引用，
所有对count的修改都要累计起来。