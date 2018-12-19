struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

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