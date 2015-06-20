package leetcode;

// 34 Search for a Range
// https://leetcode.com/problems/search-for-a-range/
//
// Given a sorted array of integers, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

public class SearchForARange {
    public int[] searchRange(int[] nums, int target) {
        int idx1 = 0;
        int idx2 = nums.length - 1;
        
        while (idx1 <= idx2) {
            int mid = (idx1 + idx2) / 2;
            if (nums[mid] < target) {
                idx1 = mid + 1;
            } else if (nums[mid] > target) {
                idx2 = mid - 1;
            } else {
                idx1 = idx2 = mid;
                break;
            }
        }
        
        if (idx1 > idx2) {
            return new int[]{-1, -1};
        }
        
        while (idx1 >= 1 && nums[idx1 - 1] == target) {
            idx1--;
        }
        while (idx2 < nums.length - 1 && nums[idx2 + 1] == target) {
            idx2++;
        }
        
        return new int[]{idx1, idx2};
    }
    
    public static void main(String[] args) {
        SearchForARange searchForARange = new SearchForARange();
        int[] result = searchForARange.searchRange(new int[]{5, 7, 7, 8, 8, 10}, 110);
        System.out.println(result[0] + ", " + result[1]);
    }
}
