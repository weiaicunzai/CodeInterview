#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() <= 1)
            return;
        
        vector<int> result;
        for(auto x : array)
            if(x % 2)
                result.push_back(x);
            
        for(auto x : array)
            if(!(x % 2))
                result.push_back(x);
        
        array = result;
    }
};