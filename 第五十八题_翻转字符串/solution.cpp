
#include <string>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int k = n;
        while(k > n)
            k %= str.size();
        
        int x = str.size() - k;
        int y = k;

        for(int i = 0; i <= x / 2; i++) swap(str[i], str[x - i - 1]);
        for(int i = x; i <= y / 2; i++) swap(str[i], str[y - i + x - 2]);
        for(int i = 0; i <= str.size() / 2; i++) swap(str[i], str[str.size() - 1 - i]);

        return str;

    }
};

int main()
{
    Solution s;
    s.LeftRotateString("abcdefg", 2);
}