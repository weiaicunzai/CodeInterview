#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        create_nodes(pHead);
        set_random(pHead);
        return split_nodes(pHead);
    }

    RandomListNode *split_nodes(RandomListNode *pHead)
    {
        if(!pHead)
            return pHead;

        RandomListNode *new_head = pHead->next;
        RandomListNode *new_node = pHead->next;
        RandomListNode *old_node = pHead;
        while(old_node && new_node->next)
        {
            old_node->next = old_node->next->next; 
            new_node->next = new_node->next->next; 
            
            old_node = old_node->next;
            new_node = new_node->next;
        }
        old_node ->next = nullptr;

        return new_head;
    }

    //set new nodes´s random pointer
    void set_random(RandomListNode* pHead)
    {
        while(pHead)
        {
            if(pHead->random)
                pHead->next->random = pHead->random->next;
            
            pHead = pHead->next->next;
        }
    }

    //create a cloned list node after each original nodes
    void create_nodes(RandomListNode *pHead)
    {
        while(pHead) 
        {
            RandomListNode *temp = new RandomListNode(pHead->label);
            temp->next = pHead->next; 
            pHead->next = temp;
            pHead = temp->next;
        }
    }
};



int main()
{
    vector<int> input = {1,2, 3, 4, 5, 6};

    RandomListNode *head = new RandomListNode(10000);
    RandomListNode *cur = head;
    for(auto x : input)
    {
        //RandomListNode* temp = new RandomListNode(x);
        cur->next = new RandomListNode(x);
        cur = cur->next;
    }
    head->next->next->next->random = head->next;
    head->next->next->next->next->random = head->next->next->next->next;

    Solution s;
    head = s.Clone(head->next);
}
