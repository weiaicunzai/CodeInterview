
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        
        if(n == 1)
            return 1;
        
        int sum = 0;
        sum = 1 + 0;
        int sum1 = 0;
        int sum2 = 1;
        for(int i = 2; i <= n; i++)
        {
            sum = sum1 + sum2;
            sum1 = sum2;
            sum2 =sum;
        }
        
        return sum;
    }
};
