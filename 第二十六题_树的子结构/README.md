## 题目描述

输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

## 解题思路
本题思路是首先遍历树A中的每个节点，如果遇到和树B根节点值一样的节点，我们再开始比较两棵树
的结构。在比较两棵树结构的时候，我们同样使用递归去遍历两棵树，但是递归退出的边界条件是树B
遍历到了叶子节点，也就是r2 == nullptr。

## C++代码
```
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2)
            return false;
        //add pRoot1 == nullptr
        if(!pRoot1)
            return false;

        bool result = false;
        //if(pRoot1->val == pRoot2->val && !result) error
        if(pRoot1->val == pRoot2->val)
            result = found(pRoot1, pRoot2);

        if(!result)
             result = HasSubtree(pRoot1->right, pRoot2);

        //if(pRoot1 && !result) error
        if(!result)
             result = HasSubtree(pRoot1->left, pRoot2);

        return result;
    }

    bool found(TreeNode *r1, TreeNode *r2)
    {
        //reach leaf node of r2
        if(!r2)
            return true;
        
        //r2 is not empty but r1 is 
        if(!r1)
            return false;

        if(r1->val != r2->val)
            return false;

        bool result;
        
        result = found(r1->left, r2->left);
        
        if(!result)
            return result;
        else
            //result = found(r1->right, r2->right);
            return found(r1->right, r2->right);
     
    }
};
```

## 易错点

冗余的判断条件：
HasSubtree开头中，已经判断了pRoot1和pRoot2是否是为空了，所以之后不需要再额外的进行判断
必定都不为空。

做这道题的一半以上的时间花在一个小bug上，
```
if(!result)
    result = HasSubtree(pRoot1->left, pRoot2);
```
之前只写了HasSubtree(pRoot1->left, pRoot2);,没写result = 的部分，花了好长时间
才找到这个bug。