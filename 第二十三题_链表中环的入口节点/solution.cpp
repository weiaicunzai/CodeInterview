struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead || !pHead -> next) return nullptr;
        ListNode* p = pHead,*q = p;
        /* 第一趟*/
        while(q -> next)
        {
            p = p -> next;
            q = q -> next -> next;
            if(p == q) break;
        }
        /* 第二趟*/
        q = pHead;
        while(p != q)
        {
            p = p -> next;
            q = q -> next;
        }
        return p;
    }
};