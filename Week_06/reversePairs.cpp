void merge(vector<int>& A, int start, int mid, int end)
{
    int n1 = (mid - start + 1);
    int n2 = (end - mid);
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j]))
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void merge2(vector<int>& nums, int left, int mid, int right){
    int n = right - left + 1;
    int* temp = new int[n];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right)
        temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    while(i <= mid) temp[k++] = nums[i++];
    while(j <= right)   temp[k++] = nums[j++];

    for(int p = 0; p < n; ++p)
        nums[left + p] = temp[p];

    delete[] temp;
}

int mergesort_and_count(vector<int>& A, int start, int end)
{
    //  时间复杂度：O(NlogN)
    // 空间复杂度：O(N)
    if (start < end) {
        int mid = (start + end) / 2;
        int count = mergesort_and_count(A, start, mid) + mergesort_and_count(A, mid + 1, end);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && A[i] > A[j] * 2LL)
                j++;
            count += j - (mid + 1);
        }
        merge2(A, start, mid, end);
        return count;
    }
    else
        return 0;
}

int reversePairs(vector<int>& nums)
{
    return mergesort_and_count(nums, 0, nums.size() - 1);
}
