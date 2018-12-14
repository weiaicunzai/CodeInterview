
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