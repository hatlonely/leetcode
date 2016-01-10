// 41 First Missing Positive
// https://leetcode.com/problems/first-missing-positive/
//
// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.

package leetcode;

public class FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            while (i != nums[i] - 1) {
                // 负数
                if (nums[i] <= 0) {
                    break;
                }
                // 数太大
                if (nums[i] - 1 >= nums.length) {
                    break;
                }
                // 要交换的两个数相同
                if (nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                // 当前数已经处在正确的位置
                if (i == nums[i] - 1) {
                    break;
                }
                // 交换i和nums[i] - 1使得第nums[i] - 1的位置满足nums[k] = k + 1
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            }
        }

        // 遍历数组，如果位置k不满足nums[k] = k + 1，则k + 1就是丢失的数
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // 如果之前的数都有，则丢失的数为下一个数，即数组长度 + 1
        return nums.length + 1;
    }

    public static void main(String[] args) {
        FirstMissingPositive firstMissingPositive = new FirstMissingPositive();
        System.out.println(firstMissingPositive.firstMissingPositive(new int[] { 3, 4, -1, 1 }));
        System.out.println(firstMissingPositive.firstMissingPositive(new int[] {}));
        System.out.println(firstMissingPositive.firstMissingPositive(new int[] { 2 }));
        System.out.println(firstMissingPositive.firstMissingPositive(new int[] { 2, 1, 0 }));
        System.out.println(firstMissingPositive.firstMissingPositive(new int[] { 1, 1 }));

    }
}
