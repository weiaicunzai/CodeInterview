## 题目描述

输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和
中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中
序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

## 解题思路
将使用递归来解答这道题。首先前序遍历的第一个元素必然是根结点。但是前序遍历无法区分
左子树和右子树，因此将利用中序遍历获得左子树和右子树的节点。有了左子树，右子树的节点，
再分别对左子树和右子树进行同样的操作，直到左子树或者右子树元素为个数为1。


## C++代码
```
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty())
            return NULL;
        
        return ConstructBinaryTreeCore(pre, vin);
        
    }
    TreeNode *ConstructBinaryTreeCore(const vector<int> &pre, const vector<int> &vin)
    {
        int root_val =  pre[0];
        TreeNode *root = new TreeNode(root_val);

        if(pre.size() == 1)
            return root;
        
        int left_length = 0;
        for(auto var = vin.begin(); var != vin.end(); var++)
        {
            if(*var == root_val)
                break;
            left_length++;
        }
        int right_length = vin.size() - 1 - left_length;

        if(left_length)
            root->left = ConstructBinaryTreeCore(vector<int>(pre.begin() + 1, pre.begin() + 1 + left_length),
                                                 vector<int>(vin.begin(), vin.begin() + left_length));
        if(right_length)
            root->right = ConstructBinaryTreeCore(vector<int>(pre.begin() + 1 + left_length, pre.end()),
                                                  vector<int>(vin.begin() + 1 + left_length, vin.end()));

        return root;
    }
};
```

## 易错点
pre.empty() 返回true代表pre为空，否则不为空
