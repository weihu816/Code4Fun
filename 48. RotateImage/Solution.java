/*
 * You are given an n x n 2D matrix representing an image.
 * Follow up: Rotate the image by 90 degrees (clockwise).
 * Could you do this in-place?
 */

// Very careful about the indices

// Iterative Solution
public class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        for (int i = 0; i < matrix.length/2; i++) {
            for (int j = 0; j < len-2*i-1; j++) {
                int x = i, y = len-1-i;
                int temp = matrix[i][i+j]; // save top-left
                matrix[x][x+j] = matrix[y-j][x]; // bot-left to top-left
                matrix[y-j][i] = matrix[y][y-j]; // bot-right to bot-left
                matrix[y][y-j] = matrix[x+j][y]; // top-right to bot-right
                matrix[x+j][y] = temp; // top-left to top-right
            }
        }
    }
}


