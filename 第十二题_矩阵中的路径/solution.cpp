class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int row = 0; row < rows; row++)
            for(int col = 0; col < cols; col++)
                if(found(matrix, row, col, str, rows, cols))
                    return true;
        
        return false;

    }
    bool found(char* m, int row, int col, char *str, int rows, int cols)
    {
        if(row < 0 || row > rows)
            return false;
        
        if(col < 0 || col > cols)
            return false;
        
        if(*str != *(m + row * cols + col))
            return false;
        
        if(*str == '\0')
            return true;
        
        if(*(m + row * cols + col) == '\0')
            return false;
        
        bool result;
        char temp = *(m + row * cols + col);
        *(m + row * cols + col) = '\0';

        result = found(m, row + 1, col, str + 1, rows, cols) ||
                 found(m, row - 1, col, str + 1, rows, cols) ||
                 found(m, row, col + 1, str + 1, rows, cols) ||
                 found(m, row, col - 1, str + 1, rows, cols);

        *(m + row * cols + col) = temp;

        return result;
    }
};

