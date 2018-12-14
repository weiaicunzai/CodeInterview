#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> result;

    vector<int> printMatrix(vector<vector<int> > matrix) {
        print_circle(matrix, 0, 0, matrix[0].size()- 1, matrix.size() - 1);
        return result;
    }

    void print_row(vector<vector<int> > &m, int row, int l_col, int r_col) 
    {
        for(int i = l_col; i <= r_col; i++)
            result.push_back(m[row][i]);
    }

    void print_col(vector<vector<int> > &m, int col, int top_row, int bot_row)
    {
        for(int i = top_row; i <= bot_row; i++)
            result.push_back(m[i][col]);
    }

    void print_two_line(vector<vector<int> > &m, int tl_col, int tl_row, int br_col, int br_row)
    {
        for(int i = tl_col; i <= br_col; i++)
            result.push_back(m[tl_row][i]);
        for(int i = br_col; i >= tl_col; i--)
            result.push_back(m[br_row][i]);
    }

    void print_circle(vector<vector<int> > &m, int tl_col, int tl_row, int br_col, int br_row)
    {
        if(tl_col > br_col)
            return;
        if(tl_row == br_row)
        {
            print_row(m, tl_row, tl_col, br_col);
            return;
        }

        if(tl_col == br_col)
        {
            print_col(m, tl_col, tl_row, br_row);
            return;
        }
        if(tl_row == br_row - 1)
        {
            print_two_line(m, tl_col, tl_row, br_col, br_row);
            return;
        }

        // add top edge
        for(int col = tl_col; col <= br_col; col++)
            result.push_back(m[tl_row][col]);
        
        //add right edge
        for(int row = tl_row + 1; row <= br_row; row++)
        {
            result.push_back(m[row][br_col]);
        }
        
        //add bottom edge
        for(int col = br_col - 1; col >= tl_col; col--)
            result.push_back(m[br_row][col]);
        
        //add left edge
        for(int row = br_row - 1; row >= tl_row + 1; row--)
            result.push_back(m[row][tl_col]);
        
        print_circle(m, tl_col + 1, tl_row + 1, br_col - 1, br_row - 1);
    }
};

int main()
{
    //vector<vector<int>> m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    //vector<vector<int>> m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    //vector<vector<int>> m = {{1, 2}, {3, 4}};
    //vector<vector<int>> m = {{1}, {2} ,{3}, {4}, {5}};
    vector<vector<int>> m = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    Solution s;
    vector<int> result = s.printMatrix(m);
    cout << endl;
    for (auto x : result)
        cout << x << endl;
}