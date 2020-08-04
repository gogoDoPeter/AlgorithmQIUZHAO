#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{

public:
    int mySqrt(int x)
    {
        // if (x == 0 || x == 1)
        //     return x;
        // long left = 1, right  = x;
        // long mid = 1;

        // while (left <= right){
        //     mid = left + (right - left) / 2;
        //     if(mid * mid > x){
        //         right = mid - 1;
        //     } else{
        //         left  = mid + 1;
        //     }
        // }
        // return (int)right;

        //牛顿迭代
        if(x == 0)  return x;
        double C = x, x0 = x;
        while(true){
            double xi = 0.5 * (x0 + C / x0);
            if(fabs(x0 - xi) < 1e-7){
                break;
            }
            x0 = xi;
        }
        return (int)x0;
    }
};

int main(int argc, char *argv[])
{
    // int g1[] = {2,2,2};
    // int s1[] = {2,2,1};
    // vector<int> vG1(g1, g1+ sizeof(g1) / sizeof(g1[0]));
    // vector<int> vS1(s1, s1+ sizeof(s1) / sizeof(s1[0]));
    // Solution so;
    // int res = so.findContentChildren(vG1, vS1);
    // printf("result: %d\n",res);

    Solution so;
    int res  = so.mySqrt(8);
    printf("res :%d\n",res);
    return 0;
}
