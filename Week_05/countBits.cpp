class Solution
{
public:
    vector<int> countBits(int num)
    {
        //时间复杂度O(n*sizeof(int)), 空间复杂度O(n)
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; ++i)
        {
            ans[i] = popCount(i);
        }
        return ans;
    }
    int popCount(int n)
    {
        int count = 0;
        while (n != 0)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};