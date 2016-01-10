// 55 Jump Game
// https://leetcode.com/problems/jump-game/
//
// Given an array of non-negative integers, you are initially positioned
// at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
//
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false.

package leetcode;

public class JumpGame {
    public boolean canJump(int[] nums) {
        int maxJump = 1; // 当前位置可以jump的最远位置
        int idx = 0;
        for (; idx < nums.length - 1; idx++) {
            maxJump--;
            if (maxJump < nums[idx]) {
                maxJump = nums[idx];
            }
            if (maxJump <= 0) {
                return false;
            }
        }

        return idx == nums.length - 1;
    }

    public static void main(String[] args) {
        JumpGame jumpGame = new JumpGame();
        System.out.println(jumpGame.canJump(new int[] { 2, 3, 1, 1, 4 }));
        System.out.println(!jumpGame.canJump(new int[] { 3, 2, 1, 0, 4 }));
        System.out.println(jumpGame.canJump(new int[] { 0 }));
    }
}
