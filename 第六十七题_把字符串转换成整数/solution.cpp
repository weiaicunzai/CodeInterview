#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        
        string temp;

        //remove spaces at head and trail
        size_t first = str.find_first_not_of(' ');
        if(first != string::npos)
        {
            size_t last = str.find_last_not_of(' ');
            temp = str.substr(first, (last - first + 1));
        }
        else
            temp = str;

        double res = 0;


        int i = 0;
        for(auto it = temp.end() - 1; it >= temp.begin(); it--)
        {
            //starts with "+"
            if(it == temp.begin() && *it == '+')
                return valid(res);
            
            //statrs with "-"
            if(it == temp.begin() && *it == '-')
                return valid(-res);
            
            //illegal input
            if(*it < 48 || *it > 57)
                return 0;
            
            res += (double)(*it - 48) * pow(10.0, i++);
        }

        return valid(res);
    }

    int valid(double n)
    {
        if(n > INT_MAX)
            return 0;
        if(n < INT_MIN)
            return 0;
        
        return n;
    }
};

int main()
{
    Solution s;
    cout << s.StrToInt("123") << endl;
    cout << s.StrToInt("+2147483647") << endl;
    cout << INT_MAX << endl;
    cout << (int)2147483647 << endl;
    double t = INT_MAX;
    cout << t << endl;
    cout << (int) t << endl;
    cout << sizeof(int) << endl;
}