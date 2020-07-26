//Java  PriorityQueue  执行会超时
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0 || k == 0)  return new int[0];
        int n = nums.length;
        int[] result = new int[n - k + 1];  //number of windows

        //PriorityQueue，即优先队列。优先队列的作用是能保证每次取出的元素都是队列中权值最小的（Java的优先队列每次取最小元素，C++的优先队列每次取最大元素）。这里牵涉到了大小关系，元素大小的评判可以通过元素本身的自然顺序（natural ordering），也可以通过构造时传入的比较器（Comparator，类似于C++的仿函数）。

        //Java中PriorityQueue实现了Queue接口，不允许放入null元素；其通过堆实现，具体说是通过完全二叉树（complete binary tree）实现的小顶堆（任意一个非叶子节点的权值，都不大于其左右子节点的权值），也就意味着可以通过数组来作为PriorityQueue的底层实现。
        //PriorityQueue<>((o1,o2)->(o2,o1)) : 通过构造时传入比较器让优先队列取最大元素
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>((o1,o2) -> (o2 - o1));
        for(int i = 0; i < n; ++i){
            int start = i - k;
            if(start >= 0)
                maxPQ.remove(nums[start]);
            maxPQ.offer(nums[i]);
            if(maxPQ.size() == k){
                result[i - k + 1] = maxPQ.peek();
            }
        }
        return result;
    }
}