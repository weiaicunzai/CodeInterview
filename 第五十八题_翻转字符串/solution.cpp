#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()) 
            return str;
        
        for(int i = 0; i < str.size() / 2; i++)
            swap(str[i], str[str.size() - 1 - i]);
        
        int start = 0;
        int end = 0;
        int pre = -1;
        for(int i = 0; i < str.size(); i++)
        {
            if(pre >= 0 && str[pre] == ' ' && str[i] != ' ')
                start = i;
            
            if(i == 0 && str[i] != ' ')
                start = i;
            
            if(pre >= 0 && str[pre] != ' ' && str[i] == ' ')
            {
                end = pre;
                swap_str(str, start, end);
            }
            
            pre++;
            if(i == str.size() - 1 && str[i] != ' ')
            {
                end = i;
                swap_str(str, start, end);
            }
                
        }

        return str;
    }
    void swap_str(string &str, int start, int end)
    {
        if(start == end)
            return;
        while(start <= end)
            swap(str[start++], str[end--]);
    }
};

int main()
{
    cout << (int)' ' << endl;
    cout << (int)'A'  << endl;
    Solution s;
    cout << s.ReverseSentence("I am a student.") << endl;;
}