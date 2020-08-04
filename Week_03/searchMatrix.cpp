class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        //从左下角上右上角寻找目标值
        int x=matrix.size()-1, y=0;
        while(x>=0 && y<matrix[0].size())
        {
            if(matrix[x][y] > target) x--;//[x,y]的值比目标值大，上移
            else if(matrix[x][y] < target)    y++;//[x,y]的值比目标值小，右移
            else return true;
        }
        return false;
    }
};