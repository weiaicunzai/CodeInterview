## 题目描述

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

## 解题思路
抽象成两个指针，一个min，一个max，min指向1,max指向2,当min和max的序列和小于sum的时候，max++，当min和max的序列和大于等于sum的时候，min++。序列和等于sum的时候，额外做一个保存的动作，记录下该序列和。

## C++代码
```
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int const largest = (sum + 1) / 2;
        vector<vector<int> >  res;
        int min = 1;
        int max = 2;

        while(max <= largest)
        {
            int temp_sum = (min + max) * (max - min + 1) / 2;
            if(temp_sum == sum)
                res.push_back(add_sum(min, max));

            if(temp_sum < sum)
                max++;
            else
                min++;
        }

        return res;
    }
    vector<int> add_sum(int min_num, int max_num)
    {
        vector<int> s;
        for(int i = min_num; i <= max_num; i++)
            s.push_back(i);
        
        return s;
    }
};

```

## 易错点
计算数列和的时候，使用等差数列公式进行计算，是max - min + 1，不要忘记 + 1.