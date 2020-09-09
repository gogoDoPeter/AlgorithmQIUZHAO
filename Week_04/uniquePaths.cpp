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
   int findMin(vector<int>& nums) {
       int left = 0, right = nums.size() - 1;
       while(left < right){
           int mid = left + (right - left) / 2;
           if(nums[mid] > nums[right]){
               left  = mid + 1;
           }else{
               right = mid;
           }
       }
        return nums[left];
    }

    int uniquePaths(int m, int n) {
        // vector<int> cur(n, 1);
        // for(int i = 1; i < m; ++i){
        //     for(int j = 1; j < n; ++j){
        //         cur[j] += cur[j -1];
        //     }
        // }
        // return cur[n - 1];


        //recursion
        //时间复杂度 O(m*n),空间复杂度O(m*n)
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i==0 || j==0)    dp[i][j]=1;
                else    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(int argc, char *argv[])
{
    // int g1[] = {2,2,2};
    // int s1[] = {2,2,1};
    // vector<int> vG1(g1, g1+ sizeof(g1) / sizeof(g1[0]));
    // vector<int> vS1(s1, s1+ sizeof(s1) / sizeof(s1[0]));
    // Solution so;
    // int res = so.findContentChildren(vG1, vS1);
    // printf("result: %d\n",res);

    Solution so;
    int arr[] = {3, 5, 7, 0, 1};
    int arr2[] = {3, 4, 0, 1, 2};
    vector<int> vData1(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int> vData2(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));

    int res  = so.uniquePaths(7,3);
    printf("res :%d\n",res);



    return 0;
}
