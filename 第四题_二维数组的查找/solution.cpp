class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //边界检查
        if (array.empty())
            return false;

        //从右上角开始遍历
        for (int col = array[0].size() - 1; col >= 0; col--)
        {
            //每一列第一个值如果大于target，则target肯定不在此列
            if(array[0][col] > target)
                continue;
            
            for(int row = 0; row < array.size(); row++)
            {
                if(target == array[row][col])
                    return true;
                
                //如果某一列的某个元素比target小，就继续往下找
                else if(target > array[row][col])
                    continue;
            }
        }

        //没有找到，返回false
        return false;
    }
};