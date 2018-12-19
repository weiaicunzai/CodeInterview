## 题目描述

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

## 解题思路
使用递归来求解。每个根节点的深度等于根节点左子树的深度和右子树深度的最大值加1。我们可以用递归遍历该根节点。而递归的终止条件
就是遇到为空的叶子结点时，返回0。


## C++代码
```
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        
        return max(TreeDepth(pRoot->left) + 1, TreeDepth(pRoot->right) + 1);
    }
};
```

## 易错点
递归的终止条件，空的叶子节点应该返回0，而不是1。