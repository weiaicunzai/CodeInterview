struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        ListNode *result;
        if(p1->val <= p2->val)
        {
           result = p1; 
           p1 = p1->next;
        }
        else
        {
            result = p2;
            p2 = p2->next;
        }

        ListNode *cur = result;
        while(p1 && p2)
        {
            if(p1->val <= p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
        }
        if(p1 && !p2)
            cur->next = p1;
        else if(!p1 && p2)
            cur->next = p2;

        return result;

    }
};