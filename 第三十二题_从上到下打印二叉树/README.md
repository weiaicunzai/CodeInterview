## 题目描述

从上往下打印出二叉树的每个节点，同层节点从左至右打印。

## 解题思路

基本上就是考察二叉树的层次遍历，但是，比层次遍历更简单的是，不需要分辨每行的元素，所有元素依照层次遍历的顺序打印出来。对于层次遍历，采用如下操作：
1. 如果头节点为空，返回空。否则将头节点放入队列中。

2. 当此队列不为空的时候，取队列的头节点，如果头节点有子节点，则将左右子节点依次放入队列中，并将头节点的值保存在结果中，最后队列头节点出列。重复步骤2直到队列为空。

3. 返回结果。

## C++代码
```
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

using namespace std;

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(!root)
            return vector<int>();
        
        queue<TreeNode *> temp;
        temp.push(root);

        vector<int> result;
        while(!temp.empty())
        {
            TreeNode *r = temp.front();

            if(r->left)
                temp.push(r->left);
            if(r->right)
                temp.push(r->right);
            
            result.push_back(r->val);
            temp.pop();
        }

        return result;
    }
};
```

## 易错点
