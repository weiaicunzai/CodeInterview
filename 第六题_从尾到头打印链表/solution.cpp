/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(!head) return vector<int>();

        //保存到栈内
        stack<ListNode *> temp;
        while(head)
        {
            temp.push(head);
            head = head->next;
        }

        vector<int> result;
        
        //出栈
        while(!temp.empty())
        {
            ListNode *h = temp.top();
            result.push_back(h->val);
            temp.pop();
        }

        return result;
    }
};