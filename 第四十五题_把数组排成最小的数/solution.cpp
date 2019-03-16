#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strings;
        for(auto x : numbers)
            strings.push_back(to_string(x));
        
        sort(strings.begin(), strings.end(), [this](string a, string b){
            return compare(a, b);
        });

        string res;
        for(auto x : strings)
            res += x;
        
        return res;
    }

    bool compare(string str1, string str2)
    {
        string str1str2 = str1 + str2;
        string str2str1 = str2 + str1;
        if(str1str2 >= str2str1)
            return false;
        else
            return true;
    }
};