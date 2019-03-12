
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    vector<string> res;
public:
    vector<string> Permutation(string str) {
        iter(str, 0);
        sort(res.begin(), res.end());
        return res;
    }

    void iter(string str, int sorted)
    {
        if(sorted == str.size() - 1)
        {
            if(find(res.begin(), res.end(), str) == res.end())
                res.push_back(str);
            return;
        }
        
        for(auto str_iter = str.begin() + sorted; str_iter != str.end(); str_iter++)
        {
            swap(*str_iter, str[sorted]);
            iter(str, sorted + 1);
            swap(*str_iter, str[sorted]);
        }
   }

};

int main()
{
    Solution s;
    s.Permutation("abc");

    
}