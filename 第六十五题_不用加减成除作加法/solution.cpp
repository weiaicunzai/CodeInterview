
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int carry = (num1 & num2) << 1;
        int non_carry = num1 ^ num2;

        while(carry & non_carry)
        {
            int temp1 = carry;
            int temp2 = non_carry;
            carry = (temp1 & temp2) << 1;
            non_carry = temp1 ^ temp2;
        }

        return carry | non_carry;
    }
};