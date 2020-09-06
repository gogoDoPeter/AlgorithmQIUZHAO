    string reverseStr(string s, int k)
    {
        // 时间复杂度O(n), 其中n表示字符串s的长度
        // 空间复杂度O(1)
        for(int i = 0; i < s.size(); i += 2*k){
            int start  = i;
            int j = min(int(s.size() - 1), start + k -1);
            if(i < j)
                reverse(s.begin() + start, s.begin() + j +1);
        }
        return s;
    }