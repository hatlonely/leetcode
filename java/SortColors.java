// 75 Sort Colors
// https://leetcode.com/problems/sort-colors/
//
// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem.

package leetcode;

import java.util.Arrays;

public class SortColors {
    public void sortColors(int[] nums) {
        int[] colors = { 0, 0, 0 };
        for (int i = 0; i < nums.length; i++) {
            colors[nums[i]]++;
        }
        int k = 0;
        for (int i = 0; i < colors.length; i++) {
            for (int j = 0; j < colors[i]; j++) {
                nums[k++] = i;
            }
        }
    }

    public static void main(String[] args) {
        SortColors sortColors = new SortColors();
        int[] nums = { 2, 1, 2, 1, 0, 1, 0, 2, 1, 2 };
        sortColors.sortColors(nums);
        System.out.println(Arrays.toString(nums));
    }
}
