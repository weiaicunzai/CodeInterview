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