    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)  return -1;
        if(n == 1)  return nums[0] == target ? 0 : -1;
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid  = (l + r) / 2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else{
                if(nums[mid] < target && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return (int)-1;
    }