#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {

        if (pushV.empty() || popV.empty())  
            return false;
        
        stack<int> s;
        auto pop_iter = popV.begin();
        for(auto x : pushV)
        {
           s.push(x);
           while(pop_iter != popV.end() && s.top() == *pop_iter)
           {
                s.pop();
                pop_iter++;
           }
        }

        return s.empty();
    }
};