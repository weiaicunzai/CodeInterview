#include <iostream>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {

         int count = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if(n & flag)
                count++;
             flag = flag * 2;
         }
         return count;
         
     }
};

#include <bitset>
class Solution {
public:
     int  NumberOf1(int n) {
         bitset<sizeof(n) * 8> num(n);
         bitset<sizeof(n) * 8> templates;
         templates.set();

         return (num &= templates).count();
         
     }
};
