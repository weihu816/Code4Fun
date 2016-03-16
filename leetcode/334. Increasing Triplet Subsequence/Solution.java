public class Solution {
    public boolean increasingTriplet(int[] nums) {
        if (nums == null || nums.length < 3)
            return false;
        int min1 = nums[0], min2 = Integer.MAX_VALUE;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > min1) {
                if (nums[i] > min2) {
                    return true;   
                } else {
                    min2= nums[i];
                }
            } else {
                min1 = nums[i];
            }
        }
        return false;
    }
}