#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        //时间复杂度O（n^2） 空间复杂度O(1)
        // int k = 0;
        // for (int i = 0; i < arr2.size(); ++i)
        // {
        //     for (int j = 0; j < arr1.size(); ++j)
        //     {
        //         if (arr1[j] == arr2[i])
        //         {
        //             swap(arr1[j], arr1[k]);
        //             k++;
        //         }
        //     }
        // }
        // sort(arr1.begin() + k, arr1.end());
        // return arr1;

        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); ++i)
        {
            mp[arr2[i]] = i;
        }
        auto cmp = [&](const auto &a, const auto &b) {
            //c++ unordered_map不允许有重复的key。因此，如果key存在，则count返回1，如果不存在，则返回0.
            if (mp.count(a) && mp.count(b))
            {
                return (mp[a] < mp[b]);
            }
            else if (mp.count(a) && !mp.count(b))
            {
                return true;
            }
            else if (!mp.count(a) && mp.count(b))
            {
                return false;
            }
            else
            { //!mp.count(a) && !mp.count(b)
                return a < b;
            }
        };

        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};

int main(int argc, char *argv[])
{
    // 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
    // 输出：[2,2,2,1,4,3,3,9,6,7,19]

    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> vRet;
    Solution so;
    vRet = so.relativeSortArray(arr1, arr2);
    for(auto i : vRet){
        // printf("%d\t",i);
        printf("%d  ",i);
    }
    return 0;
}