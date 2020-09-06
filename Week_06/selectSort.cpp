void selectSort(int count, int arr[]){
    //时间复杂度O(n^2)  空间复杂度O(1)
    //Sort Step: 每次找最小的值，然后放到待排序数组的起始位置
    //表现最稳定的排序算法之一，用它的时候，数据规模越小越好，唯一好处不占用额外内存空间
        int minIndex, temp;
        for(int i = 0; i < count -1; ++i){
            minIndex = i;
            for(int j = i + 1; j < count; ++j){
                if(arr[j] < arr[minIndex])
                    minIndex = j;
            }
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }