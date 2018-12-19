struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1 = 0;
        int l2 = 0;

        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        while(p1)
        {
            p1 = p1->next;
            l1++;
        }
        while(p2)
        {
            p2 = p2->next;
            l2++;
        }

        p1 = pHead1;
        p2 = pHead2;

        if(l1 > l2)
            for(int i = 0; i < l1 - l2; i++)
                p1 = p1->next;
        if(l1 < l2)
            for(int i = 0; i < l2 - l1; i++)
                p2 = p2->next;
        
        while(p1 && p2)
        {
            if(p1 == p2)
                break;
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};