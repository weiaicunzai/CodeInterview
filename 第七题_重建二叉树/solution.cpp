
#include <vector>
#include <iostream>

using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
void print(TreeNode *root)
{
    if(!root)
        return;
    if(root->left)
        print(root->left);
    cout << root->val << endl;
    if(root->right)
        print(root->right);
        
}
int main()
{
    Solution s;
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    TreeNode *root = s.reConstructBinaryTree(pre, vin);
    print(root);

}