## 题目描述

输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)

## 解题思路

这答题很简单，最重要的是弄懂题意，路径指的是，从二叉树根节点到叶子节点的值，必须是根节点到叶子节点，和分支节点没关系，也不能是子树的根节点。所以，我们使用先根遍历，去求每条路径上的值就行了。其实有一个细节必须要注意，就是必须是先根遍历，不能中序遍历和后续遍历，因为我们必须要从根节点开始访问，如果从叶子节点开始访问，那么计算路径的值就会很难。确定了必须用先根遍历，我们就可以用递归来写了。每次访问一个节点，就将该节点的值保存起来，并且将路径和加上该节点的值。如果路径和为期待的值，并且该节点是叶子节点，则返回。返回的时候，记得将该节点的值出栈，可以看做回溯。如果路径和不是期待的值，则继续遍历树，遍历完该节点的时候，同样需要将该节点的值出栈。

## C++代码
```
class Solution {
    vector<vector<int> > res;
    vector<int> path;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find_path(root, expectNumber, 0);
        return res;
    }

    void find_path(TreeNode *root, int expectNumber, int sum)
    {
        if(!root)
            return;
        
        sum += root->val;
        path.push_back(root->val);

        if (sum == expectNumber && !root->left && !root->right)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }

        find_path(root->left, expectNumber, sum);
        find_path(root->right, expectNumber, sum);

        path.pop_back();//backtracing
   }
};
```

## 易错点

可能比较容易出错的地方，就是忘记访问完某个节点之后，需要将该节点的值出栈，类似回溯。

