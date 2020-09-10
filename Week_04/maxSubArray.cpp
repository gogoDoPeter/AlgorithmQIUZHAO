#include <iostream>
// #include <unordered_map>
// #include <hash_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int>& nums) {
        //1, brute-force
        // int maxVal = INT_MIN, total;
        // for(int i = 0; i < nums.size(); ++i){
        //     total = 0;
        //     for(int j = i; j < nums.size(); ++j){
        //         total += nums[j];
        //     }
        //     maxVal = max(maxVal, total);
        // }
        // return maxVal;

        //2, //dp(i) = max(dp(i-1) + nums[i], nums[i])
        //时间复杂度：O(n) 空间复杂度O(1)
        //为了更好理解下面DP方程，假设nums[i]为正值来理解
        //dp(i) = max(0, dp(i-1)) + nums[i] <==> //dp(i) = max(dp(i-1) + nums[i], nums[i])
        /*int pre = 0, maxVal = nums[0];
        for(const auto &x: nums){
            //dp(i) = max(dp(i-1) + nums[i], nums[i])
            pre = max(pre+x, x);
            maxVal = max(maxVal, pre);
        }
        return maxVal;*/

        //3, dp(i) = max(0, dp(i-1)) + nums[i]
        int pre = 0, maxVal = nums[0];
        for(int i = 0; i < nums.size(); ++i){
            // dp[i] = max(dp(i - i), 0) + nums[i];
            pre = max(nums[i], nums[i] + pre);
            maxVal = max(pre, maxVal);
        }
        return maxVal;
    }
    
};

int main()
{
    int ret = 0;
    Solution so;
    //[-2,1,-3,4,-1,2,1,-5,4]
    // int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int arr[] = {-2,-1,-3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
 
    ret = so.maxSubArray(nums);
    
    printf("ret : %d\n",ret);

    return 0;
}