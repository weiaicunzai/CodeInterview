#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

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

        path.pop_back();
   }


};
