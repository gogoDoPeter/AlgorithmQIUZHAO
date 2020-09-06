bool isAnagram(string s, string t)
{
    //时间复杂度O(n) 空间复杂度O(1), 空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为O(1)
    if (s.size() != t.size())
        return false;
    int str[26] = {0};
    for (int i = 0; i < s.size(); ++i)
    {
        str[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); ++i)
    {
        if (--str[t[i] - 'a'] < 0)
            return false;
    }
    return true;
}