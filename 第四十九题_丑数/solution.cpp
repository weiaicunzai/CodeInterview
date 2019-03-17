#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7)
            return index;
        
        vector<int> res;
        res.reserve(index); // avoid vector rellocation to make iterator valid
        res.push_back(1);
        auto t2 = res.begin();
        auto t3 = res.begin();
        auto t5 = res.begin();

        while(res.size() != index)
        {
            int min_temp = min(*t5 * 5, min(*t2 * 2, *t3 * 3));
            res.push_back(min_temp);

            if(*t5 * 5 == min_temp) t5++;
            if(*t3 * 3 == min_temp) t3++;
            if(*t2 * 2 == min_temp) t2++;
        }

        return res.back();
    }
};

int main()
{
    Solution s;
    int res = s.GetUglyNumber_Solution(7);
    cout << res << endl;
}