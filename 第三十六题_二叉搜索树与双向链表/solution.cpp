#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//class Solution {
//public:
//    TreeNode* Convert(TreeNode* pRootOfTree)
//    {
//        if(!pRootOfTree)
//            return pRootOfTree;
//
//        TreeNode *head, *tail;
//        get_linkedlist(pRootOfTree, head, tail);
//
//        return head;
//    }
//
//    void get_linkedlist(TreeNode* pRootOfTree, TreeNode *&head, TreeNode *&tail)
//    {
//        if(!pRootOfTree)
//            return;
//        
//        if(!pRootOfTree->left && !pRootOfTree->right)
//        {
//            head = pRootOfTree;
//            tail = pRootOfTree;
//            return;
//        }
//
//        TreeNode *left_head;
//        TreeNode *left_tail;
//        get_linkedlist(pRootOfTree->left, left_head, left_tail);
//
//        if(pRootOfTree->left)
//        {
//            left_tail->right = pRootOfTree;
//            pRootOfTree->left = left_tail;
//            left_head->left = nullptr;
//            head = left_head;
//            tail = pRootOfTree;
//        }
//        else
//        {
//           head = pRootOfTree;
//           tail = pRootOfTree;
//        }
//
//        TreeNode *right_head;
//        TreeNode *right_tail;
//        get_linkedlist(pRootOfTree->right, right_head, right_tail);
//
//        if(pRootOfTree->right)
//        {
//            pRootOfTree->right = right_head;
//            right_head->left = pRootOfTree;
//            right_tail->right = nullptr;
//            tail = right_tail;
//        }
//        else
//        {
//            pRootOfTree->right = nullptr;
//        }
//    }
//};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return pRootOfTree;
            
        TreeNode *pre;
        get_linkedlist(pRootOfTree, pre);

        while(pre->left)
            pre = pre->left;
        
        return pre;
    }

    void get_linkedlist(TreeNode* pRootOfTree, TreeNode *&pre)
    {
        if(!pRootOfTree)
            return;

        TreeNode *cur = pRootOfTree;

        get_linkedlist(cur->left, pre);


        pre = cur->left;
        if(pre)
            pre->right = cur;
        pre = cur;

        get_linkedlist(cur->right, pre);

        
    }
};