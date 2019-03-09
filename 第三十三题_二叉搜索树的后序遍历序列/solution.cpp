#include <vector>
#include <iostream>

using namespace std;

/*
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;

        int flag = 0; //flag = 0 smaller flag = 1 larger

        int last = sequence.back();
        for(auto x : sequence)
        {
            if(x < last && flag)
                return false;
            if (x > last && !flag)
                flag = 1;
        }

        return true;
    }
};
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return judge(sequence, 0, sequence.size() - 1);
    }

    bool judge(vector<int> &sequence, int l, int r)
    {
        if(r < l)
            return false;
        if(r == l)
            return true;
        
        int last = sequence[r];
        int index = r;

        for(int i = 0 + l; i < r; i++)
        {
            //find the left tree and right tree
            if(sequence[i] > last)
            {
                index = i;
                break;
            }
        }

        //右子树有比last小的值
        for(int i = index; i < r; i++)
            if(sequence[i] < last)
                return false;

        bool left = true;
        //有左子树
        if (index - l)
            left = judge(sequence, l, index - 1);

        bool right = true;
        //有右子树
        if (r - index)
            right = judge(sequence, index, r - 1);

        return left && right;
    }
};

int main()
{
    
    cout << (1 ^ 1) << endl;
    cout << (1 ^ 0) << endl;

    Solution s;
    //vector<int> test = {1, 2, 3, 4, 5};
    vector<int> test = {5,4,3,2,1};
    cout << s.VerifySquenceOfBST(test) << endl;
}