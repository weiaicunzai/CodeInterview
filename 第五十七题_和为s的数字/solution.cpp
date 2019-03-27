#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2)
            return array;
        auto min_num = array.begin();
        auto max_num = array.end() - 1;

        vector<int> res;
        while(min_num < max_num)
        {
            if(*min_num + *max_num == sum)
            {
                if(res.empty())
                {
                    res.push_back(*min_num);
                    res.push_back(*max_num);
                }
                else
                {
                    int num1 = *min_num * *max_num;
                    int num2 = res[0] * res[1];
                    if(num1 < num2)
                    {
                        res.clear();
                        res.push_back(*min_num);
                        res.push_back(*max_num);
                    }
                }
            }
            if(*min_num + *max_num < sum)
                min_num++;
            else
                max_num--;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> temp = {1,2,4,7,11,15};
    s.FindNumbersWithSum(temp, 15);
}