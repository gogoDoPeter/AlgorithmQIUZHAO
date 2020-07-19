#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {

public:
	//遍历两边哈希表
	vector<int> twoSum2(vector<int>& nums, int target) {
		unordered_map<int, int> myHash;
		vector<int> out;
		for (int i = 0; i < nums.size(); i++) {
			myHash[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (myHash[target - nums[i]] && (myHash[target - nums[i]] != i)) {
				out.push_back(i);
				out.push_back(myHash[target - nums[i]]);
				return out;
			}
		}
		return out;
	}

	//遍历两边哈希表
	vector<int> twoSum(vector<int>& nums, int target) {
		// vector<int> out;
		unordered_map<int, int> myHash;
		for(int i = 0; i< nums.size(); ++i){
			if(myHash.find(target - nums[i]) != myHash.end()){
				// out.push_back(myHash[target - nums[i]]);
				// out.push_back(i);
				// return out;
				return {myHash[target - nums[i]], i};
			}
			myHash[nums[i]] = i;
		}

		// return out;
	}

	//暴力解法
	vector<int> twoSum3(vector<int>& nums, int target) {
		vector<int> out;

		for(int i = 0; i < nums.size(); ++i){
			for(int j = i+1; j < nums.size(); ++j){
				if(nums[i] + nums[j] == target){
					out.push_back(i);
					out.push_back(j);
					return out;
				}
			}
		}

		return out;
	}
};

int main()
{
	Solution so;
	// int arr[4] = {3,3,1,2};
	// int arr[4] = {2,7,11,15};
	int arr[4] = {3,2,4};
	vector<int> arr_(arr, arr + 4);
	vector<int> out  =	so.twoSum3(arr_, 6);
	
	printf("%d,%d\n",out[0],out[1]);
	return 0;
}	
