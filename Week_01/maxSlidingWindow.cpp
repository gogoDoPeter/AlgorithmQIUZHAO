#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

class Solution {
class MonotonicQueue{
private:
    deque<int> data;
public:
    void pop(int n){
        if(!data.empty() && n == data.front())
            data.pop_front();
    }

    int max(){
        return data.front();
    }

    void push(int n){
        while(!data.empty() && data.back() < n)
            data.pop_back();
        data.push_back(n);
    }
};

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //1 暴力求解：
        // vector<int> out;
        // if(nums.size() * k == 0){
        //     return out;
        // }
        // int max;
        // for(int i = 0; i < nums.size() - k + 1; ++i){
        //     // max = nums[i];
        //     max = INT_MIN;
        //     for(int j = i; j < k + i; ++j){
        //         if(nums[j] > max)
        //             max = nums[j];
        //     }
        //     out.push_back(max);
        // }
        // return out;

        //2 单调队列
        if(k <= 1)  return nums;
        MonotonicQueue window;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(i < k - 1){
                window.push(nums[i]);
            }else{
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};

int main()
{
	Solution so;
	int arr[] = {7,2,4};
	// int arr[4] = {2,7,11,15};
	vector<int> arr_(arr, arr + 3);
	vector<int> out  =	so.maxSlidingWindow(arr_, 2);
	// so.rotate(arr_,3);
	for(auto in : out)
		cout<<in;

	return 0;
}	
