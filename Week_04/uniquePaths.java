class Solution {
    public int uniquePaths(int m, int n) {
        //时间复杂度：O(m*n)  两个循环，需要m*n次计算得到结果 
        //空间复杂度：O(n) 只需定义n个数组存放结果
        int[] cur = new int[n];

        Arrays.fill(cur, 1);
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
}