int maxProduct(vector<int> &nums)
{
    //时间复杂度：O(n)  空间复杂度O(n)
    vector<int> maxF(nums), minF(nums);
    for (int i = 1; i < nums.size(); ++i)
    {
        maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
        minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
    }
    return *max_element(maxF.begin(), maxF.end());
}
