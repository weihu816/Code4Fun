public class Solution {
    
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;
        int ans = 0;
        int m = matrix.length, n = matrix[0].length;
        int flag[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(flag[i], -1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = dfs(matrix, flag, i, j, Integer.MIN_VALUE);
                ans = val > ans ? val : ans;
            }
        }
            
        return ans;
    }
    
    public int dfs(int[][] matrix, int[][] flag, int i, int j, int pre) {
        int m = matrix.length, n = matrix[0].length;
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= pre) {
            return 0;
        }
        if (flag[i][j] != -1) {
            return flag[i][j];
        }
        flag[i][j] = 0;
        int v1 = dfs(matrix, flag, i-1, j, matrix[i][j]);
        int v2 = dfs(matrix, flag, i+1, j, matrix[i][j]);
        int v3 = dfs(matrix, flag, i, j+1, matrix[i][j]);
        int v4 = dfs(matrix, flag, i, j-1, matrix[i][j]);
        flag[i][j] = Math.max(Math.max(Math.max(v1, v2), v3), v4) + 1;
        return flag[i][j];
    }
}