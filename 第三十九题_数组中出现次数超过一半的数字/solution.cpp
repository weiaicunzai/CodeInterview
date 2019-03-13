#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int number = numbers[0];
        int count = 1;
        for(auto x : numbers)
        {
            if(count == 0)
                number = x;
            
            if(number != x)
                count--;
            else
                count++;
        }

        count = 0;
        for(auto x : numbers)
            if(x == number)
                count++;

        if(count > numbers.size() / 2)
            return number;
        return 0;
    }
};