package leetcode;

// 31 Next Permutation
// https://leetcode.com/problems/next-permutation/
//
// Implement next permutation, which rearranges numbers into the lexicographically 
// next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order
// (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
//
// Here are some examples. Inputs are in the left-hand column and 
// its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

public class NextPermutation {
    public void nextPermutation(int[] nums) {
        int idx1 = nums.length - 1;     // 从后往前第一个不是按照降序排列的数
        while (idx1 > 0 && nums[idx1] <= nums[idx1 - 1]) {
            idx1--;
        }
        
        // 已经是最大值（降序排列）
        if (idx1 == 0) {
            reverse(nums, 0, nums.length - 1);
            return;
        }
        idx1--;
        
        int idx2 = nums.length - 1;     // 从后往前第一个比nums[idx1]大的数
        while (nums[idx2] <= nums[idx1]) {
            idx2--;
        }
        
        // swap(nums, idx1, idx2)
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
        
        reverse(nums, idx1 + 1, nums.length - 1);
    }
    
    public void reverse(int[] nums, int beginIndex, int endIndex) {
        int middle_index = (beginIndex + endIndex + 1) / 2;
        for (int i = beginIndex; i != middle_index; i++) {
            int temp = nums[i];
            nums[i] = nums[beginIndex + endIndex - i];
            nums[beginIndex + endIndex - i] = temp;
        }
    }
    
    public static void main(String[] args) {
        NextPermutation nextPermutation = new NextPermutation();
//      int[] nums = new int[]{1, 2, 3, 4};
        int[] nums = new int[]{1, 5, 1};
        for (int i = 0; i < 6; i++) {
            nextPermutation.nextPermutation(nums);
            for (int j = 0; j < nums.length; j++) {
                System.out.print(nums[j]);
            }
            System.out.println("");
        }
    }
}
