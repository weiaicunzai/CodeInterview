## 题目描述

输入一棵二叉树，判断该二叉树是否是平衡二叉树。

## 解题思路
简单的使用一个函数计算一棵树的深度，使用后续遍历的方法，这样，每一个节点就都可以得到该节点
左子树和右子树的深度了，如果左子树和右子树的深度相差绝对值大于1,则表明该树不是二叉平衡树。

## C++代码
```

class Solution
{
    bool is_balanced;
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) 
            return true;
        is_balanced = true;
        
        Depth(pRoot);
        return is_balanced; 
    }
    int Depth(TreeNode *pRoot)
    {
        if(!pRoot)
            return 0;
        
        int left = Depth(pRoot->left);
        int right = Depth(pRoot->right);

        if(abs(left - right) > 1)
            is_balanced = false;

        return max(left, right) + 1;
    }
};
```


## 易错点
