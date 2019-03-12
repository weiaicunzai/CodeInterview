## 题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

## 解题思路

如图，可以看作一个是一个递归过程。
![avatar](img.png)
## C++代码
```
class Solution {
    vector<string> res;
public:
    vector<string> Permutation(string str) {
        iter(str, 0);
        sort(res.begin(), res.end());
        return res;
    }

    void iter(string str, int sorted)
    {
        if(sorted == str.size() - 1)
        {
            if(find(res.begin(), res.end(), str) == res.end())
                res.push_back(str);
            return;
        }
        
        for(auto str_iter = str.begin() + sorted; str_iter != str.end(); str_iter++)
        {
            swap(*str_iter, str[sorted]);
            iter(str, sorted + 1);
            swap(*str_iter, str[sorted]);
        }
   }
};
```

## 易错点
iter(str, sorted + 1) 这行代码不能写在函数结尾。


