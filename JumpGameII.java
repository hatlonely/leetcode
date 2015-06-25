// 45 Jump Game II
// https://leetcode.com/problems/jump-game-ii/
//
// Given an array of non-negative integers, you are initially positioned
// at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// For example:
// Given array A = [2,3,1,1,4]
//
// The minimum number of jumps to reach the last index is 2.
// (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

package leetcode;

import java.util.Arrays;

public class JumpGameII {
    public int jump(int[] nums) {
        // 动态规划，step[i]记录从位置i到最后最少的步数
        int[] steps = new int[nums.length];
        // 用一个比较大的数填充，MAX_VALUE会溢出，因此选MAX_VALUE / 2
        Arrays.fill(steps, Integer.MAX_VALUE / 2);

        steps[nums.length - 1] = 0; // 最后一个位置用0填充
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] + i >= nums.length - 1) {
                // 可以直接一步到达
                steps[i] = 1;
            } else if (nums[i] == 0) {
                continue;
            } else {
                // 第i的最小步数为当前可以到达的步数+1
                steps[i] = steps[i + nums[i]] + 1;
                for (int j = nums[i] - 1; j >= 1; j--) {
                    // 不会有比2步更少的步数
                    if (steps[i] == 2) {
                        break;
                    }
                    if (steps[i] > steps[i + j] + 1) {
                        steps[i] = steps[i + j] + 1;
                    }
                }
            }
        }

        return steps[0];
    }

    public static void main(String[] args) {
        JumpGameII jumpGameII = new JumpGameII();
        System.out.println(jumpGameII.jump(new int[] { 2, 3, 1, 1, 4 }) == 2);
        System.out.println(jumpGameII.jump(new int[] { 1 }) == 0);
        System.out.println(jumpGameII.jump(new int[] { 5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8,
                1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3, 8, 5 }) == 5);
        int[] array = new int[25002];
        for (int i = 0; i < array.length; i++) {
            array[i] = array.length - 2 - i;
        }
        array[array.length - 2] = 1;
        array[array.length - 1] = 0;
        System.out.println(jumpGameII.jump(array) == 2);
    }
}
