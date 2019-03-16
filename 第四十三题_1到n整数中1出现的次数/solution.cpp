

#include <iostream>

using namespace std;

//class Solution {
//public:
//    int NumberOf1Between1AndN_Solution(int n)
//    {
//        int count = 0;
//        for(int i = 1; i <= n; i++)
//            count += contains_one(i);
//        
//        return count;
//    }
//
//    int contains_one(int n)
//    {
//        int count = 0;
//        while(n)
//        {
//            if(n % 10 == 1)
//                count++;
//            n /= 10;
//        }
//
//        return count;
//    }
//};

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for(int i = 1; i <= n; i*=10)
            count += ((n / i) + 8) / 10 * i + ((n / i) % 10 == 1) * ((n % i) + 1);
        
        return count;
    }
};

int main()
{
    Solution s;
    int count = s.NumberOf1Between1AndN_Solution(55);
    cout << count << endl;
}