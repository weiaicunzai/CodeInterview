## 题目描述

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

## 解题思路

我们如果使用int类型的数进行比较，在数字拼接的过程中，很可能会出现溢出的情况。因此，我们可以通过转换成字符串来解决这个问题。
之后使用排序：
如果字符串a+b > b+a，则a>b
如果字符串a+b < b+a，则a<b
如果字符串a+b = b+a, 则a=b
有了字符串大小的比较规则，使用排序算法就可以得到最终的序列。

## C++代码
```
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strings;
        for(auto x : numbers)
            strings.push_back(to_string(x));
        
        sort(strings.begin(), strings.end(), [this](string a, string b){
            return compare(a, b);
        });

        string res;
        for(auto x : strings)
            res += x;
        
        return res;
    }

    bool compare(string str1, string str2)
    {
        string str1str2 = str1 + str2;
        string str2str1 = str2 + str1;
        if(str1str2 >= str2str1)
            return false;
        else
            return true;
    }
};
```

## 易错点
