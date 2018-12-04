struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead)
            return nullptr;
        if(!pHead->next)
            return pHead;
        
        ListNode *pre = nullptr;
        ListNode *cur = pHead;

        while(cur->next)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        cur->next = pre;
        return cur;
    }
};