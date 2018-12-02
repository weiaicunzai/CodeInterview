#include <iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 1)
            return 0;
        
        double result = 1;
        for(int i = 0; i < abs(exponent); i++)
            result *= base;

        if(exponent < 0)
            return 1 / result;
        
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.Power(2, -3) << endl;;
}