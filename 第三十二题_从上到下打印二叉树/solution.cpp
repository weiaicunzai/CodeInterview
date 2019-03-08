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