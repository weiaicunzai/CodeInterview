#include <vector>
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

void print(ListNode *head);

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead)
            return nullptr;
        
        ListNode *cur = pListHead;
        ListNode *knode = nullptr;
        int count = 1;

        if(k == 1)
        {
            while(cur->next)
                cur = cur->next;
            return cur;
        }

        //cur->next, not cur 
        while(cur->next)
        {
            if(count == k - 1)
                knode = pListHead;
            
            //move knode to next, except for
            //the first ti
            //if(knode != pListHead && knode) //error
            if(count != k - 1 && knode)
                knode = knode->next;
            
            count++;
            cur = cur->next;
        }

        return knode;
    }
};

void print(ListNode *head)
{
    cout << "--------" << endl;
    while(head)
    {
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    ListNode *head;
    ListNode dummy(100000);
    head = &dummy;
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    ListNode *p = head;
    for(auto x : nums)
    {
        ListNode *tmp = new ListNode(x);
        //cout << tmp.val << endl;
        p->next = tmp;
        p = p->next;

    }

    p = head;
    print(p);


    p = head->next;
    Solution s;
    ListNode *res = s.FindKthToTail(p, 10);
    print(res);
}