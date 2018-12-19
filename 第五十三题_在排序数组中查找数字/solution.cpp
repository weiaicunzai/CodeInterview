#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int left = get_first_k(data, k, 0, data.size() - 1);
        int right = get_last_k(data, k , 0, data.size() - 1);
        if(left == -1 || right == -1)
            return 0;
        
        return right - left + 1;
    }

    int get_last_k(const vector<int> &data, int k, int low, int high)
    {
        if(low > high)
            return -1;
        
        int mid = (low + high) / 2;

        if(data[mid] == k && mid == data.size() - 1)
            return mid;
        
        int index;

        if(data[mid] < k)
            index = get_last_k(data, k, mid + 1, high);
        
        if(data[mid] > k)
            index = get_last_k(data, k, low, mid - 1);
        
        if(data[mid] == k)
        {
            if(data[mid + 1] == k)
                index = get_last_k(data, k, mid + 1, high);
            else
                index = mid;
        }

        return index;
    }
    int get_first_k(const vector<int> &data, int k, int low, int high)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (data[mid] == k && mid == 0)
            return mid;

        int index;

        if (data[mid] < k)
            index = get_first_k(data, k, mid + 1, high);
        if (data[mid] > k)
            index = get_first_k(data, k, low, mid - 1);
        if (data[mid] == k)
        {
            if (data[mid - 1] == k)
                index = get_first_k(data, k, low, mid - 1);
            else
                index = mid;
        }

        return index;
    }
};