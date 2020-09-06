    int firstUniqChar(string s) {
        //时间复杂度O(n)  空间复杂度O(1)
        //构造一个哈希数组，对应26个字母，初值为0，每出现一次对应元素+1
        int hash[26] = {0};
        for(char ch:s){
            hash[ch - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }