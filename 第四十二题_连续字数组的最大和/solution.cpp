#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int greatest = INT_MIN;        

        int sum = 0;
        for(auto x : array)
        {
            //[1,-2,3,10,-4, 7, 2,-5]
            //[-2,-8,-1,-5,-9]
            //[a, b, c, d]
            if(sum < 0)
                sum = x;
            else
                sum += x;

            if(sum > greatest)
                greatest = sum;
        }

        return greatest;
    }
};