#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size())
            return vector<int>();
        priority_queue<int> pq;

        for(int i = 0; i < input.size(); i++)
        {
            if(i < k)
            {
                pq.push(input[i]);
                continue;
            } 
            if(input[i] < pq.top())
            {
                pq.pop();
                pq.push(input[i]);
            }
        }

        vector<int> res;
        while(!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v = {4,5,1,6,2,7,3,8};
    v = s.GetLeastNumbers_Solution(v, 4);
    for(auto x : v)
    {
        cout << x << endl;
    }
}