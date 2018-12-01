class Solution {
public:
    int jumpFloorII(int number) {
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        
        int number2 = 2;

        int result;
        for(int i = 3; i <= number; i++)
        {
            result = number2 * 2;
            number2 = result;
        }
        return result;
    }
};