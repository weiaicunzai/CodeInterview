## 题目描述

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.
则经过替换之后的字符串为We%20Are%20Happy。

## 解题思路
如果从字符串开始往后读，碰到一个空格就替换成```%20```，由于```%20```有3个字节，所以每次替换
都会另该空格后面的字符串后移两个字节。当字符串太多时，将形成瓶颈。因此，我们讲从后往前进行空格的
替换。首先遍历字符串，统计出字符串中的空格个数，然后计算出空格被替换后的字符串的长度，即原始字符串
长度加上空格个数*2。之后用两个指针分别指向原始字符串的末尾和新字符串的末尾，从后往前进行复制。如果
原始字符串遇到了空格，则新字符串对应的位置用```%20```替代。


## C++代码
```
#include <iostream>
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(length == 0)
            return;
        

        int i = 0;
        int count = 0;

        //统计多少个空格以及字符串长度
        while(str[i] != '\0')
        {
            if(str[i] == ' ')
                count++;
            i++;
        }

        
        int new_length = i + count * 2;
        int old_length = i;

        //从后往前复制
        for(int elem_index = old_length; elem_index >= 0; elem_index--)
        {
            if(str[elem_index] != ' ')
            {
              str[new_length--] = str[elem_index];
            }
            else
            {
                str[new_length--] = '0';
                str[new_length--] = '2';
                str[new_length--] = '%';
            }
        }

	}
};
```

## 易错点
新字符串的长度是原始字符串长度+空格个数*2，而不是3，因为空格为1字节，```%20```为
3字节，比空格多2个字节。

```char * str```和```char str[]```相同点都是可以直接通过加法取得对应位置的元素，但是不同点是，
```char * str```的值可以改变，而```char str[]```不能改变。如：
```
char * str = "abc";
str++; //ok
char str1[] = “abc”;
str++; //error
```
char str[]的类型是const char *因此无法修改。

```char str[] = "abc"```中，```str```的长度是4，最后一个元素为```\0```。
```
char str[4] = "abc"; //ok
char str[3] = "abc"; //error
```