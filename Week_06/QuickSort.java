public class QuickSort {

    public static void quickSort(int[] array, int begin, int end){
        if(end <= begin)    return;
        int pivot = partition(array, begin, end);
        quickSort(array, begin, pivot - 1);
        quickSort(array, pivot + 1, end);
    }

    static int partition(int[] a, int begin, int end) {
        //pivot : 标杆位置; counter:以end的数组值做为标杆在数组中应该的下标位置;  counter-begin:小于Pivot的元素个数
        int counter = begin, pivot = end;
        for(int i = begin; i < end; ++i){
            if(a[i] < a[pivot]){
                int temp = a[counter]; a[counter] = a[i]; a[i] = temp;
                counter++;
            }
        }
        int temp = a[pivot]; a[pivot] = a[counter]; a[counter] = temp;
        return counter;
    }

    public static void main(String[] args){
        int[] array = {4, 8, 1, 3, 10, 9};
        quickSort(array, 0, array.length - 1);
        for(int i = 0; i < array.length; ++i){
            System.out.println(array[i]);
        }

    }
}
