class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        int str[26] = {};
        for(int i = 0; i < s.size(); ++i){
            str[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); ++i){
            if(--str[t[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};