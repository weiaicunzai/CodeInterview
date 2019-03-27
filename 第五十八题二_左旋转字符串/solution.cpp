#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty())
            return str;
        int k = n;
        while(k > n)
            k %= str.size();
        
        int y = str.size() - k;
        int x = k;

        for(int i = 0; i < x / 2; i++) swap(str[i], str[x - i - 1]);
        for(int i = 0; i < y / 2; i++) swap(str[i + x], str[x + y - i - 1]);
        for(int i = 0; i < str.size() / 2; i++) swap(str[i], str[x + y - 1 - i]);

        return str;

    }
};

int main()
{
    Solution s;
    cout << s.LeftRotateString("abcdefg", 2) << endl;
}