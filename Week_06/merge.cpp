vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //时间复杂度O(nlogn), 复杂度取决于排序的开销，如果用快排，堆排，归并排序，就是O(nlogn)
        //空间复杂度O(1)  取决于排序空间开销，最优是O(1)
        if(intervals.size() == 0)   return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++){
            int L = intervals[i][0], R = intervals[i][1];
            // # 如果列表为空，或者当前区间与上一区间不重合，直接添加
            if(!merged.size() || merged.back()[1] < L){
                merged.push_back({L, R});
            }else{//否则的话，就可以与上一区间进行合并
                merged.back()[1] = max(R, merged.back()[1]);
            }
        }
        return merged;
    }