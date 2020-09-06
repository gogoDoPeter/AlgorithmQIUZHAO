#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int *temp = new int[right - left + 1];  //临时数组存合并后的有序序列
    while (i <= mid && j <= right)
        temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int p = 0; p < right - left + 1; ++p)
        arr[left + p] = temp[p];
    delete[] temp;//删掉堆区的内存
}

void mergeSort(int array[], int left, int right)
{
    //时间复杂度O(N*LogN) 空间复杂度O(N) 需要N个临时数组存放中间有序序列
    //1，把长度为N的输入序列分成两个长度为N/2的子序列
    //2, 对这两个子序列分别采用归并排序
    //3, 将两个排序好的序列合并成一个最终的排序序列
    if (right <= left)  return;
    int mid = (right + left) >> 1;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main(int argc, char *argv[])
{
    int array[] = {3, 1, 2, 4, 5, 8, 7, 6};
    // int array[] = {3, 1, 2};
    int length = sizeof(array) / sizeof(array[0]);
    mergeSort(array, 0, length - 1);
    for (int i = 0; i < length; ++i)
        cout << array[i] << " ";

    return 0;
}