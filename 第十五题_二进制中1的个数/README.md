## 题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

## 解题思路
一个最简单的思路，就是先判断某个数的二进制的最后一位是不是1，如果是1的话，
将该数的右移1位，再次判断最后一位是不是1，如此循环下去，直到数为0为止。但是
这种思路对于负数是有问题的。因为数的二进制都是用补码表示的，而负数的最高位是1，
如果将负数的二进制表示右移，则最高位就会变为0，成了正数。因此我们可以用1,10,100
等分别和原来数字做bitwise and,算出对应位有多少个。或者直接使用C++的bitset模版类
来生成全是1的二进制，和原数做位运算。


## C++代码
```
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
```
```
class Solution {
public:
     int  NumberOf1(int n) {
         bitset<sizeof(n) * 8> num(n);
         bitset<sizeof(n) * 8> templates;
         templates.set();

         return (num &= templates).count();
         
     }
};
```

## 易错点
用和1的与运算来判断某二进制数的某一位是否是1是常用的手段。

无符号数溢出的规则是：
UINT_MAX + 1  = 0
UINT_MAX + 2  = 1

unsigned char, unsinged short等都一样。比如unsinged char，
unsinged char a;
a = 256; //可以编译通过，会警告

由于unsigned char最大值是255，256赋值给a，会导致溢出，a就会等于0，
同理，257赋值给a，则会得到1。
