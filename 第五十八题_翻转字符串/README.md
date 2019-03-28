## 题目描述

牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

## 解题思路
首先将整个字符串逆序，之后对于每个单词进行逆序。

## C++代码
```
class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()) 
            return str;
        
        for(int i = 0; i < str.size() / 2; i++)
            swap(str[i], str[str.size() - 1 - i]);
        
        int start = 0;
        int end = 0;
        int pre = -1;
        for(int i = 0; i < str.size(); i++)
        {
            if(pre >= 0 && str[pre] == ' ' && str[i] != ' ')
                start = i;
            
            if(i == 0 && str[i] != ' ')
                start = i;
            
            if(pre >= 0 && str[pre] != ' ' && str[i] == ' ')
            {
                end = pre;
                swap_str(str, start, end);
            }
            
            pre++;
            if(i == str.size() - 1 && str[i] != ' ')
            {
                end = i;
                swap_str(str, start, end);
            }
                
        }

        return str;
    }
    void swap_str(string &str, int start, int end)
    {
        if(start == end)
            return;
        while(start <= end)
            swap(str[start++], str[end--]);
    }
};
```

## 易错点
逆序每个单词的函数有点难写，直接简单粗暴的使用两个指针从两头分别往中间走就行了。
