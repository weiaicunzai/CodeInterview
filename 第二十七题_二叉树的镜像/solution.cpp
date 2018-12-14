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