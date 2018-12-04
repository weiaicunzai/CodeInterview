#include <iostream>

class Solution {
public:
    int rectCover(int number) {
        if(number == 0)
            return 0;
        if(number == 1)
            return 1;
        
        if(number == 2)
            return 2;
        
        int number1 = 1;
        int number2 = 2;
        int result;
        for(int i = 3; i <= number; i++)
        {
            result = number1 + number2;
            number1 = number2;
            number2 = result;
        }
        
        return result;
    }
};