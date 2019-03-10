## 题目描述


输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。


## 解题思路
可以看成一个递归问题，由于二叉搜索树的左子树的所有值都比根节点小，右子树都比根节点大，我们可以先将左子树排序，然后再和根节点链接，最后再和右子树链接，是一个递归问题。


## C++代码
```
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return nullptr;
            
        TreeNode *pre = nullptr;
        get_linkedlist(pRootOfTree, pre);

        TreeNode *res = pRootOfTree;
        while(res->left)
            res = res->left;
        
        return res;
    }

    void get_linkedlist(TreeNode* cur, TreeNode *&pre)
    {
        if(!cur)
            return;

        get_linkedlist(cur->left, pre);

        cur->left = pre;
        if(pre)
            pre->right = cur;
        pre = cur;

        get_linkedlist(cur->right, pre);
    }
};

```

## 易错点
oj的一个小bug，如果pre不赋值为nullptr，则会把之前测试用例的值也带进来，很奇怪。