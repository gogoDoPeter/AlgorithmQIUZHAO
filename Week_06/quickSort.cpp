void quickSort(int array[], int begin, int end)
{
    //时间复杂度O(N * LogN)  空间复杂度O(N * LogN)
    //数组取标杆pivot，将小元素放到pivot左边，大元素放pivot右边，依次对左边
    //和右边的子数组进行快排，达到整个序列有序
    if (begin >= end) return;
    int pivot = partition(array, begin, end);
    quickSort(array, begin, pivot - 1);
    quickSort(array, pivot + 1, end);
}
int partition(int a[], int begin, int end)
{
    //pivot : 标杆位置; counter:以end的数组值做为标杆在数组中应该的下标位置;  counter-begin:小于Pivot的元素个数
    int counter = begin, pivot = end;
    for (int i = begin; i < end; ++i)
    {
        if (a[i] < a[pivot])
        {
            swap(a[i], a[counter]);
            counter++;
        }
    }
    swap(a[counter], a[pivot]);
    return counter;
}