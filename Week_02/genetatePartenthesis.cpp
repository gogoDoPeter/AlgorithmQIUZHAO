#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{

public:
    void _generate(int left, int right, int n, string s, vector<string> &ans)
    {
        if (left == n && right == n)
        {
            ans.push_back(s);
            return;
        }

        if (left < n)
            _generate(left + 1, right, n, s + "(", ans);
        if (left > right)
            _generate(left, right + 1, n, s + ")", ans);
    }
    //时间复杂度：O(n)
    //空间复杂度：O(n)
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        _generate(0, 0, n, "", ans);
        return ans;
    }
};

int main(int argc, char *argv[])
{

    Solution so;
    vector<string> ans;
    ans = so.generateParenthesis(3);
    for (string s : ans)
    {
        // printf("%s\n",s.c_str());
        cout << s.c_str() << endl;
    }

    return 0;
}
