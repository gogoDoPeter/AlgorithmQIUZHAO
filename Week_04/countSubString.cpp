int countSubstrings(string s)
{
    //时间复杂度O(n^2)  空间复杂度O(1)
    int n = s.size(), ans = 0;
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        int l = i / 2, r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            --l;
            ++r;
            ++ans;
        }
    }
    return ans;
}
