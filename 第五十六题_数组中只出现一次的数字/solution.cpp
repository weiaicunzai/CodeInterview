#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int total = 0; 
        for(auto x : data)
            total ^= x;
        
        int count = 0;
        while(!(total % 2))
        {
            total /= 2;
            count++;
        }

        *num1 = *num2 = 0;
        for(auto x : data)
        {
            int temp = x;
            for(int i = 0; i < count; i++)
                temp /= 2;
            
            if(temp % 2)
                *num1 ^= x;
            else
                *num2 ^= x;
        }
    }
};


int main()
{
    vector<int> a = {2,4,3,6,3,2,5,5};
    int *a1, *b1;
    cout << *a1 << endl;
    cout << *b1 << endl;
    Solution s;
    s.FindNumsAppearOnce(a, a1, b1);
    //cout << *a1 << endl;
    //cout << *b1 << endl;
    //cout << (13 ^ 0 ) << endl;;
    //cout << (13 ^ 1 ) << endl;;
}