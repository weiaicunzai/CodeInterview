#include <vector>
#include <algorithm> 
#include <iostream>

using   namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()) 
            return 0;
        
        return merge_sort(data, 0, data.size() - 1) % 1000000007;
    }

    long long merge_sort(vector<int>& data, int low, int hight)
    {
        if(hight == low)
            return 0;
        
        int mid = low + (hight - low) / 2;
        long long count_left = merge_sort(data, low, mid);
        long long count_right = merge_sort(data, mid + 1, hight);

        auto it_left = data.begin() + mid;
        auto it_right = data.begin() + hight;
        vector<int> temp(hight - low + 1);
        long long count = 0;
        auto it = temp.end() - 1;

        while(distance(data.begin() + low, it_left) >= 0 && distance(data.begin() + mid + 1, it_right) >= 0)
        {
            if(*it_left > *it_right)
            {
                *it-- = *it_left--;
                count += distance(data.begin() + mid, it_right);
            }
            else
                *it-- = *it_right--;
        }

        while(distance(data.begin() + low, it_left) >= 0)
            *it-- = *it_left--;
        while(distance(data.begin() + mid + 1, it_right) >= 0)
            *it-- = *it_right--;
        
        //copy temp back to original data;
        copy_n(temp.begin(), temp.size(), data.begin() + low);

        return count_right + count_left + count;
    }
};

int main()
{
    //vector<int> res = {12, 54, 22, 2, 100};
    vector<int> res = {54, 12, 1, 33};
    //vector<int> res = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
    Solution s;
    int count = s.InversePairs(res);

    cout << count << endl;
}