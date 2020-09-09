#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution
{

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //动态规划 
        //世间复杂度O(m*n), 空间复杂度O(m),m表示输入grid的行数
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        vector<int> f(n);
        f[0] = (obstacleGrid[0][0] == 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(obstacleGrid[i][j] == 1){
                    f[j] = 0;
                    continue;
                }
                if(j - 1 >= 0 && obstacleGrid[i][j - 1] == 0){
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
