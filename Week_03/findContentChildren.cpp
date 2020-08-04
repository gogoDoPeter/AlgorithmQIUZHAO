#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;


class Solution
{

public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, result = 0;
        while(i != g.size() && j != s.size() ) {
            if(g[i] <= s[j]){
                i++;j++;
                result++;
            }else{
                j++;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    int g1[] = {2,2,2};
    int s1[] = {2,2,1};
    vector<int> vG1(g1, g1+ sizeof(g1) / sizeof(g1[0]));
    vector<int> vS1(s1, s1+ sizeof(s1) / sizeof(s1[0]));
    Solution so;
    int res = so.findContentChildren(vG1, vS1);
    printf("result: %d\n",res);

    return 0;
}
