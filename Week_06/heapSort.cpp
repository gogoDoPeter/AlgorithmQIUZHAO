#include <iostream>
#include <queue>
using namespace std;

int reversePairs(vector<int> &nums)
{
    
}

int main(int argc, char *argv[])
{
    int array[] = {3, 1, 2, 4, 5, 8, 7, 6};
    // int array[] = {3, 1, 2};
    int length = sizeof(array) / sizeof(array[0]);
    heap_sort(array, length);
    for (int i = 0; i < length; ++i)
        cout << array[i] << " ";

    return 0;
}