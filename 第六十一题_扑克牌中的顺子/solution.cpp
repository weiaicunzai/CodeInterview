
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5)
            return false;

        map<int, int> stats;
        int max_num = 1;
        int min_num = 13;
        for(auto x : numbers)
        {
            if(x != 0)
            {
                if(x > max_num)
                    max_num = x;
                if(x < min_num)
                    min_num = x;
                
                stats[x]++;
            }
        }

        if(max_num - min_num >= 5)
            return false;

        for(auto it = stats.begin(); it != stats.end(); it++)
            if(it->second > 1)
                return false;

        return true;
    }
};