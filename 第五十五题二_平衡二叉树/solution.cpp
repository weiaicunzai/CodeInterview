#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

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
