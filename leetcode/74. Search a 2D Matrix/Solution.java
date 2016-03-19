public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        int m = matrix.length, n = matrix[0].length;
        int i = 0, j = m - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (matrix[mid][0] < target) {
                i = mid + 1;
            } else if (matrix[mid][0] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }
        int row = i;
        if (row == m || target < matrix[row][0]) {
            if (row == 0) return false;
            row--;
        }
        i = 0;
        j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (matrix[row][mid] < target) {
                i = mid + 1;
            } else if (matrix[row][mid] > target) {
                j = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}