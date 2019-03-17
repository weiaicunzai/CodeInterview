#include <iostream>
#include <map>
#include<typeinfo>

using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> stats;
        for(auto iter = str.begin(); iter != str.end(); iter++)
            stats[*iter]++;
        
        for(auto iter = str.begin(); iter != str.end(); iter++)
            if(stats[*iter] == 1)
                return distance(str.begin(), iter);
        
        return -1;
    }
};

int main()
{
    string a = "1234";
    auto f = a.begin();
    cout << typeid(*f).name() << endl;
    cout << typeid(a[0]).name() << endl;
    cout << typeid(a).name() << endl;
}