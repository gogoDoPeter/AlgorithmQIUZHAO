 void bubbleSort(int count, int arr[])
    {
        //时间复杂度O(n^2), 空间复杂度O(1)
        //嵌套循环，每次查看相邻元素如果逆序，则交换
        //添加Flag 对于数组已经有序或者前半部分已经有序，优化循环次数
        bool flag = true;
        for(int i = 0; i < count - 1; ++i){
            for(int j = 0; j < count - 1 - i; ++j){
                if(arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    flag = false;
                    printf("do swap\n");
                }
            }
            if(flag)    break;
        }
    }