#include <vector>

using namespace std;

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

int main()
{
    Solution s;
    s.FindContinuousSequence(9);

}