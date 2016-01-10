// 42 Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/
//
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
//
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

package leetcode;

public class TrappingRainWater {
    public int trap(int[] height) {
        int sum = 0;
        int left = 0;
        int right = height.length - 1;

        // 找到两边的最高点，每次都从较低的一端开始计算
        while (left < right) {
            // 左端最高点
            while (left < right && height[left] <= height[left + 1]) {
                left++;
            }
            // 右端最高点
            while (left < right && height[right] <= height[right - 1]) {
                right--;
            }

            if (height[left] < height[right]) {
                int pos = left;
                while (height[pos] > height[++left]) {
                    sum += height[pos] - height[left];
                }
            } else if (height[left] > height[right]) {
                int pos = right;
                while (height[pos] > height[--right]) {
                    sum += height[pos] - height[right];
                }
            } else {
                // 左端和右端一样大，任选一边
                // 左端和右端重合，退出
                if (left != right) {
                    int pos = right;
                    while (height[pos] > height[--right]) {
                        sum += height[pos] - height[right];
                    }
                    ;
                }
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        TrappingRainWater trappingRainWater = new TrappingRainWater();
        System.out
                .println(trappingRainWater.trap(new int[] { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }));
        System.out.println(trappingRainWater.trap(new int[] { 0, 1, 0 }));
        System.out.println(trappingRainWater.trap(new int[] { 1 }));
        System.out.println(trappingRainWater.trap(new int[] {}));
    }
}
