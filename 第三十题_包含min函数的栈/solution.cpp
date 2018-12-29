#include <iostream>
#include <stack>

using namespace std;
class Solution {

    stack<int> s1;
    stack<int> s2;

    int s1_min = INT_MAX;

public:
    void push(int value) {
        if(value < s1_min)
        {
            s2.push(value);
            s1_min = value;
        }
        else
        {
            s2.push(s1_min);
        }

        s1.push(value);
    }
    void pop() {
         s1.pop();
         s2.pop();
    }
    int top() {
        return s1.top(); 
    }
    int min() {
        return s2.top(); 
    }
};