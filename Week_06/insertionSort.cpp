void insertionSort(int count, int arr[]){
        //时间复杂度O(n^2), 空间复杂度O(1)
        //从前到后逐步构建有序序列
        //通常采用in-place排序，在从后向前扫描中，需要反复将已排序元素向后挪位，为最新元素提供插入空间
        int preIndex, current;
        for(int i = 1; i < count; ++i){
            preIndex = i - 1;
            current = arr[i];
            while(preIndex >= 0 && arr[preIndex] > current){
                arr[preIndex + 1] = arr[preIndex];
                preIndex--;
            }
            arr[preIndex + 1] = current;
        }
    }